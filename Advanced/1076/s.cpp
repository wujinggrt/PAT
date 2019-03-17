#include <cstdio>

#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        for (int j = 0; j < num; ++j) {
            int follow;
            cin >> follow;
            // follow 发的信息可以被 i forward.
            graph[follow - 1][i] = 1;
        }
    }
    int k;
    cin >> k;
    vector<int> query(k);
    for (auto& q: query) {
        cin >> q;
    }
    struct Node {
        int level;
        int index;
    };
    function<int(int)> bfs = [&] (int index) {
        if (l == 0) {
            return 0;
        }
        int numEffected = 0;
        vector<int> visited(graph.size(), 0);
        queue<Node> q;
        q.push({l, index});
        visited[index] = 1;
        while (q.empty() == false) {
            auto cur = q.front();
            q.pop();
            // 传播的网到尽头了
            if (cur.level == 0) {
                continue;
            }
            for (int v = 0; v < graph.size(); ++v) {
                // visited == 0，没有访问过
                if (visited[v] == 0 && graph[cur.index][v] == 1) {
                    visited[v] = 1;
                    q.push({cur.level - 1, v});
                    ++numEffected;
                }
            }
        }
        return numEffected;
    };
    for (auto id: query) {
        cout << bfs(id - 1) << "\n";
    }
    // for (auto& row: graph) {
    //     for (auto n: row) {
    //         cout << n << " ";
    //     }
    //     cout << "\n";
    // }
}