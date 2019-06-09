#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  freopen("i.dat", "r", stdin);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  vector<int> indegree(n + 1, 0);
  for (int i = 0; i < m; ++i) {
    int from, to;
    cin >> from >> to;
    graph[from].push_back(to);
    indegree[to]++;
  }
  int k;
  cin >> k;
  bool is_first = true;
  for (int i = 0; i < k; ++i) {
    // 可能会更改入度的数据，所以复制一份
    vector<int> temp_indegree(begin(indegree), end(indegree));
    bool is_topological = true;
    for (int j = 0; j < n; ++j) {
      int vertex;
      cin >> vertex;
      if (temp_indegree[vertex] != 0) {
        is_topological = false;
      }
      for (auto v: graph[vertex]) {
        --temp_indegree[v];
      }
    }
    if (!is_topological) {
      printf("%s%d", is_first ? "" : " ", i);
      is_first = false;
    }
  }
}
