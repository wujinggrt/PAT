#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> datas{
        {'P', 0},
        {'A', 0},
        {'T', 0},
        {'e', 0},
        {'s', 0},
        {'t', 0}
    };
    int max_count = 0;
    for (const auto& c: s) {
        auto it = datas.find(c);
        if (it != datas.end()) {
            ++(it->second);
            if (max_count < it->second) {
                max_count = it->second;
            }
        }
    }
    for (int i = 0; i < max_count; ++i) {
        printf(
            "%s%s%s%s%s%s", 
            (datas['P']-- > 0 ? "P" : ""),
            (datas['A']-- > 0 ? "A" : ""),
            (datas['T']-- > 0 ? "T" : ""),
            (datas['e']-- > 0 ? "e" : ""),
            (datas['s']-- > 0 ? "s" : ""),
            (datas['t']-- > 0 ? "t" : "")
        );
    }
    return 0;
}