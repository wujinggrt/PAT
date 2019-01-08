#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

enum class Color {
    White = 0,
    Gray = 1,
    Black = 2
};

using Highway = vector<vector<int>>;
using Visited = vector<Color>;

Highway highways;
Visited visited;

// 返回连通分量的个数
int dfs();
void visit(int pos);

int main() {
    // 使用cin的话需要这一行来提高cin效率
    // ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    highways = Highway(n, vector<int>(n, 0));
    visited = Visited(n, Color::White);
    for (int i = 0; i < m; ++i) {
        int from, to;
        // cin >> from >> to;
        scanf("%d %d", &from, &to);
        highways[from - 1][to - 1] = 1;
        highways[to - 1][from - 1] = 1;
    }
    vector<int> rows(n, 0);
    vector<int> cols(n, 0);
    for (int i = 0; i < k; ++i) {
        int lost;
        cin >> lost;
        rows.swap(highways[lost - 1]);
        for (int i = 0; i < n; ++i) {
            // backup
            cols[i] = highways[i][lost - 1];
            // 设置与lost点连接的点为断开
            highways[i][lost - 1] = 0;
        }
        auto connected_component = dfs();
        cout << connected_component - 2 << "\n";
        // fill放在函数dfs()的最后一句（return之前），最后一个测试点会超时
        fill(visited.begin(), visited.end(), Color::White);
        rows.swap(highways[lost - 1]);
        for (int i = 0; i < n; ++i) {
            highways[i][lost - 1] = cols[i];
        }
    }
}

int dfs() {
    int connected_component = 0;
    auto n = highways.size();
    for (int i = 0; i < n; ++i) {
        if (visited[i] == Color::White) {
            ++connected_component;
            visit(i);
        }
    }
    return connected_component;
}

void visit(int pos) {
    visited[pos] = Color::Gray;
    auto n = highways.size();
    for (int i = 0; i < n; ++i) {
        if (visited[i] == Color::White && highways[pos][i]) {
            visit(i);
        }
    }
    visited[pos] = Color::Black;
}
