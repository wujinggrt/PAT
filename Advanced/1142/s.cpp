#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
  freopen("i.dat", "r", stdin);
  int nv, ne;
  cin >> nv >> ne;
  vector<vector<int>> graph(nv + 1, vector<int>(nv, 0));
  for (int i = 0; i < ne; ++i) {
    int a, b;
    cin >> a >> b;
    graph[a][b] = 1;
    graph[b][a] = 1;
  }
  int m;
  cin >> m;
  for (; m-- > 0; ) {
    int k;
    cin >> k;
    vector<int> queries(k);
    vector<int> appeared_in_queries(nv + 1, 0);
    for (auto& q: queries) {
      cin >> q;
      appeared_in_queries[q] = 1;
    }
    auto is_clique = [&] () {
      for (int i = 0; i < k; ++i) {
        for (int j = i + 1; j < k; ++j) {
          if (graph[queries[i]][queries[j]] == 0) {
            cout << "Not a Clique\n";
            return false;
          }
        }
      }
      return true;
    } ();
    if (!is_clique) {
      continue;
    }
    auto is_maximal = [&] () {
      for (int i = 1; i <= nv; ++i) {
        // test if it can insert
        if (!appeared_in_queries[i]) {
          auto connected_all_queries = all_of(begin(queries), end(queries), [&] (int q) {
            return graph[i][q] == 1;
          });
          if (connected_all_queries) {
            return false;
          }
        }
      }
      return true;
    } ();
    cout << (is_maximal ? "Yes\n" : "Not Maximal\n");
  }
}
