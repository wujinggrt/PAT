#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    uint32_t m;
    uint32_t n;
    cin >> m >> n;
    vector<uint32_t> colors(n * m);
    unordered_map<uint32_t, uint32_t> color_table;
    color_table.reserve(m * n);
    if (m * n == 0) {
        return 0;
    }
    uint32_t max_count = 0;
    uint32_t max_color = 0;
    for (auto& c: colors) {
        scanf("%u", &c);
        auto iter = color_table.find(c);
        if (iter != end(color_table)) {
            ++(iter->second);
            if (iter->second > max_count) {
                max_color = c;
                max_count = iter->second;
            } else if (iter->second == max_count) {
                max_color = c;
            }
        } else {
            color_table[c] = 1;
            if (max_count < 1) {
                max_count = 1;
                max_color = c;
            }
        }
    }
    // sort(begin(colors), end(colors));
    // uint32_t tmp_count = 1;
    // for (uint32_t i = 1; i < m * n; ++i) {
    //     if (colors[i] != colors[i - 1]) {
    //         tmp_count = 1;
    //     } else {
    //         tmp_count ++;
    //     }
    //     if (max_count < tmp_count) {
    //         max_color = colors[i];
    //         max_count = tmp_count;
    //     }
    // }
    cout << max_color;
}