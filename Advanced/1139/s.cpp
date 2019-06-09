#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    freopen("i.dat", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> guys(n, vector<int>(n, 0));
    vector<int> index_to_id(n);
    unordered_map<int, int> id_to_index;
    int cur_index = -1;
    for (; m-- > 0; ) {
        int a, b;
        cin >> a >> b;
        auto a_insert_res = id_to_index.insert({a, cur_index + 1});
        int a_index = a_insert_res.first->second;
        if (a_insert_res.second) {
            ++cur_index;
            index_to_id[a_index] = a;
        }
        auto b_insert_res = id_to_index.insert({b, cur_index + 1});
        int b_index = b_insert_res.first->second;
        if (b_insert_res.second) {
            ++cur_index;
            index_to_id[b_index] = b;
        }
        guys[a_index][b_index] = 1;
        guys[b_index][a_index] = 1;
    }
    int k;
    cin >> k;
    for (; k-- > 0; ) {
        int a, b;
        cin >> a >> b;
        // 1 同
        // 2 异性
        if (id_to_index.find(a) == end(id_to_index) || id_to_index.find(b) == end(id_to_index)) {
            cout << 0 << "\n";
            continue;
        }
        auto a_index = id_to_index[a];
        auto b_index = id_to_index[b];
        vector<pair<int, int>> relations;
        for (int i = 0; i < guys[a_index].size(); ++i) {
            // 朋友是同性
            if (i == a_index || i == b_index || guys[a_index][i] != 1 || a * index_to_id[i] < 0) {
                continue;
            }
            // 与 a 的朋友有关系
            for (int j = 0; j < guys[i].size(); ++j) {
                // 还需要和 b 有关系，这个朋友不是自己。。。
                if (j == a_index || j == b_index || i == j || guys[i][j] != 1 || guys[j][b_index] != 1 || b * index_to_id[j] < 0) {
                    continue;
                }
                relations.push_back({abs(index_to_id[i]), abs(index_to_id[j])});
            }
        }
        sort(begin(relations), end(relations), [] (const pair<int, int>& lhs, const pair<int, int>& rhs) {
            if (lhs.first != rhs.first) {
                return lhs.first < rhs.first;
            } else {
                return lhs.second < rhs.second;
            }
        });
        cout << relations.size() << "\n";
        for (auto p: relations) {
            cout << p.first << " " << p.second << "\n";
        }
    }
}
