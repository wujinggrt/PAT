#include <unordered_map>
#include <string>
#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.get();
    unordered_map<string, int> mars{
        {"tret", 0},
        {"jan", 1},
        {"feb", 2},
        {"mar", 3},
        {"apr", 4},
        {"may", 5},
        {"jun", 6},
        {"jly", 7},
        {"aug", 8},
        {"sep", 9},
        {"oct", 10},
        {"nov", 11},
        {"dec", 12},

        {"tam", 13},
        {"hel", 13 * 2},
        {"maa", 13 * 3},
        {"huh", 13 * 4},
        {"tou", 13 * 5},
        {"kes", 13 * 6},
        {"hei", 13 * 7},
        {"elo", 13 * 8},
        {"syy", 13 * 9},
        {"lok", 13 * 10},
        {"mer", 13 * 11},
        {"jou", 13 * 12}
    };
    unordered_map<string, string> earth;
    for (auto& e: mars) {
        earth[to_string(e.second)] = e.first;
    }
    for (int i = 0; i < n; ++i) {
        string origin;
        int decoded = 0;
        getline(cin, origin);
        if (origin[0] >= '0' && origin[0] <= '9') {
            decoded = stoi(origin);
            if (decoded < 13) {
                cout << earth[origin] << '\n';
            } else {
                cout << earth[to_string(decoded - decoded % 13)];
                if (decoded % 13 != 0) {
                    cout << " " << earth[to_string(decoded % 13)];
                }
                cout << '\n';
            }
        } else {
            istringstream is(origin);
            string s;
            is >> s;
            auto it = mars.find(s);
            if (it == mars.end()) {
                return -1;
            }
            auto temp = it->second;
            decoded += temp;
            // 第一个为tret，大小为4，其他为3
            if (origin.size() > 4) {
                is >> s;
                it = mars.find(s);
                if (it != mars.end()) {
                    decoded += it->second;
                }
            }
            cout << decoded << '\n';
        }
    }
    return 0;
}