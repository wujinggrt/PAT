#include <vector>
#include <functional>
#include <queue>
#include <iostream>
#include <cstdio>
using namespace std;

/**
 * 每次按照列访问，
 * 分别是 (0, 1, 0), y 前进，
 * （0, -1, 0) y back.
 * */
int X[6] = {0,0,0,0,-1,1};
int Y[6] = {1,-1,0,0,0,0};
int Z[6] = {0,0,1,-1,0,0};

struct Node {
    int x;
    int y;
    int z;
};

int main() {
    int m, n, l, t;
    cin >> m >> n >> l >> t;
    vector<vector<vector<int>>> slices(l, vector<vector<int>>(m, vector<int>(n, 0)));
    vector<vector<vector<int>>> visited(l, vector<vector<int>>(m, vector<int>(n, 0)));
    for (auto& mat: slices) { // l
        for (auto& row: mat) { // m
            for (auto& entry: row) { // n
                cin >> entry;
            }
        }
    }
    int ans = 0;
    auto check = [&] (int x, int y, int z) {
        // 下标有效
        if (x < 0 || x >= l ||
            y < 0 || y >= m ||
            z < 0 || z >= n) {
            return false;
        }
        // 能顾访问吗
        if (slices[x][y][z] == 0 || visited[x][y][z]) {
            return false;
        }
        return true;
    };
    function<int(int, int, int)> bfs = [&] (int x, int y, int z) {
        int total = 0;
        queue<Node> q;
        visited[x][y][z] = 1;
        q.push({x, y, z});
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            ++total;
            // 考虑 6 个方向
            for (int i = 0; i < 6; ++i) {
                int ax = front.x + X[i];
                int ay = front.y + Y[i];
                int az = front.z + Z[i];
                if (check(ax, ay, az)) {
                    q.push({ax, ay, az});
                    visited[ax][ay][az] = 1;
                }
            }
        }
        if (total >= t) { // 阈值
            return total;
        } else {
            return 0;
        }
    };
    for (int x = 0; x < l; ++x) {
        for (int y = 0; y < m; ++y) {
            for (int z = 0; z < n; ++z) {
                if (slices[x][y][z] == 1 && !visited[x][y][z]) {
                    ans += bfs(x, y, z);
                }
            }
        }
    }
    cout << ans << "\n";
}