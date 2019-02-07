#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    uint32_t m;
    uint32_t n;
    cin >> m >> n;
    vector<uint32_t> colors(n * m);
    unordered_map<uint32_t, uint32_t> color_table;
    color_table.reserve(m * n);
    for (auto& c: colors) {
        scanf("%u", &c);
        color_table[c]++;
    }
    for (auto& entry: color_table) {
        if (entry.second > (m * n / 2)) {
            cout << entry.first;
            break;
        }
    }
}