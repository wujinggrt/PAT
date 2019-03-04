#include <numeric>
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

void DFS() {
    int32_t n;
    int32_t m;
    cin >> n >> m;
    vector<int32_t> coins(n);
    for (auto& face: coins) {
        cin >> face;
    }
    if (accumulate(begin(coins), end(coins), 0) < m) {
        printf("No Solution\n");
        return;
    }
    sort(begin(coins), end(coins));
    bool collected = false;
    vector<int32_t> path;
    auto printer = [&] () {
        bool first = true;
        for (auto face: path) {
            if (!first) {
                cout << " ";
            } else {
                first = false;
            }
            cout << face;
        }
    };
    function<void(int32_t, int32_t)> dfs = [&] (int32_t index, int32_t sum) {
        // pop all function stack;
        if (collected) {
            return;
        }
        if (sum == m) {
            collected = true;
            printer();
            return;
        }
        // 剪枝
        if (sum > m) {
            return;
        }
        // dfs core
        for (int32_t i = index; i < n; ++i) {
            path.push_back(coins[i]);
            dfs(i + 1, sum + coins[i]);
            path.pop_back();
        }
    };
    dfs(0, 0);
    if (!collected) {
        cout << "No Solution\n";
    }
}

void BagProblem() {
    int32_t n;
    int32_t m;
    cin >> n >> m;
    vector<int32_t> coins(n);
    for (auto& face: coins) {
        cin >> face;
    }
    if (accumulate(begin(coins), end(coins), 0) < m) {
        printf("No Solution\n");
        return;
    }
    sort(begin(coins), end(coins), greater<int32_t>());
    bool collected = false;
    struct CoinRecord {
        int32_t total;
        bool selected;
    };
    // 计算背包问题的表 n + 1 * m + 1
    vector<vector<CoinRecord>> bag_table(n + 1, vector<CoinRecord>(m + 1, {0, false}));
    // bag_table[i][j] = max(bag_table[i - 1][j].total, bag_table[i - 1][j - c[i]].total)
    for (int32_t i = 1; i <= n; ++i) {
        // 对于j小于当前coins[i]的情况，说明背包装不下，不考虑
        for (int32_t weight = 1; weight <= m; ++weight) {
            // 注意第i个coin面值为coins[i - 1]
            // 装不下了 or max 是不选取这个coin
            if (coins[i - 1] > weight) {
                bag_table[i][weight].total = bag_table[i - 1][weight].total;
                bag_table[i][weight].selected = false;
            } else {
                if (bag_table[i - 1][weight].total <= (bag_table[i - 1][weight - coins[i - 1]].total + coins[i - 1])) {
                    bag_table[i][weight].total = bag_table[i - 1][weight - coins[i - 1]].total + coins[i - 1];
                    bag_table[i][weight].selected = true;
                } else {
                    bag_table[i][weight].total = bag_table[i - 1][weight].total;
                    bag_table[i][weight].selected = false;
                }
            }
        }
    }
    if (bag_table[n][m].total != m) {
        cout << "No Solution\n";
    } else {
        vector<int32_t> track;
        int32_t capacity = m;
        int32_t index = n;
        for (; capacity != 0;) {
            for (; !bag_table[index][capacity].selected;) {
                index--;
            }
            track.push_back(coins[index - 1]);
            capacity -= coins[index - 1];
            index--;
        }
        bool first = true;
        for (auto t: track) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << t;
        }
        cout << "\n";
    }
}

int main() {
    DFS();
}