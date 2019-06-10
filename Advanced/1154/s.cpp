#include <cstdio>
#include <set>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  freopen("i.dat", "r", stdin);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    int from, to;
    cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
  int k;
  cin >> k;
  vector<int> node_color(n);
  for (; k-- != 0; ) {
    set<int> color_set;
    for (auto& node: node_color) {
      cin >> node;
      color_set.insert(node);
    }
    auto is_coloring = [&] () {
      for (int i = 0; i < n; ++i) {
        for (auto other_side: graph[i]) {
          // same color on both certain edge side.
          if (node_color[i] == node_color[other_side]){
            return false;
          }
        }
      }
      return true;
    } ();
    if (is_coloring) {
      cout << color_set.size() << "-coloring\n";
    } else {
      cout << "No\n";
    }
  }
}
