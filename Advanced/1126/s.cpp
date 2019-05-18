#include <functional>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from - 1][to - 1] = 1;
        graph[to - 1][from - 1] = 1;
    }
    int eulerian_odd = 0;
    vector<int> degree;
    transform(begin(graph), end(graph), back_inserter(degree), [&] (decltype(graph.front())& row) {
        int ret = count(begin(row), end(row), 1);
        if (ret % 2 != 0) {
            ++eulerian_odd;
        }
        return ret;
    });
    cout << count(begin(graph.front()), end(graph.front()), 1);
    for_each(begin(graph) + 1, end(graph), [] (decltype(graph.front())& row) {
        cout << " " << count(begin(row), end(row), 1);
    });
    cout << "\n";
    string ans;
    switch (eulerian_odd) {
    case 0:
        ans = "Eulerian";
        break;
    case 2:
        ans = "Semi-Eulerian";
        break;
    default:
        ans = "Non-Eulerian";
        break;
    }
    vector<int> visited(n, 0);
    function<void(int)> dfs = [&] (int i) {
        visited[i] = 1;
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] != 0 && visited[j] != 1) {
                dfs(j);
            }
        }
    };
    dfs(0);
    cout << (all_of(begin(visited), end(visited), [] (int i) { return i == 1; }) ? ans : string{"Non-Eulerian"}) << "\n";
    return 0;
}
