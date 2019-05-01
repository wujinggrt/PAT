#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vertices(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        vertices[from - 1][to - 1] = 1;
        vertices[to - 1][from - 1] = 1;
    }
    int k;
    cin >> k;
    vector<vector<int>> queries(k);
    vector<int> visited(n, 0);
    for (auto& row: queries) {
        int num;
        cin >> num;
        row = vector<int>(num);
        copy_n(istream_iterator<int>(cin), num, begin(row));
        bool has_cycle = true;
        visited[row.front() - 1]++;
        for (int i = 1; i < row.size(); ++i) {
            int cur = row[i] - 1;
            int pre = row[i - 1] - 1;
            if (vertices[cur][pre] == 0) { // 不连通
                has_cycle = false;
                break;
            }
            visited[cur]++;
        }
        if (has_cycle) {
            int tmp = 0;
            has_cycle = all_of(begin(visited), end(visited), [&tmp] (int num) {
                if (num == 1) {
                    return true;
                } else if (tmp == 0 && num == 2) {
                    ++tmp;
                    return true;
                } else {
                    return false;
                }
            });
            has_cycle = (tmp == 1 ? has_cycle : false); // 是否有一个回到原点, 否则同以前一样
            has_cycle = (row.front() == row.back() ? has_cycle : false); // 从尾回到头
        }
        cout << (has_cycle ? "YES\n" : "NO\n");
        fill(begin(visited), end(visited), 0);
    }
}