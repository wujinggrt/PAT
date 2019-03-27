#include <cstdio>

#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string sell, want;
    cin >> sell >> want;
    unordered_map<char, int> demond;
    for (auto c: want) {
        ++(demond[c]);
    }
    int extra = 0;
    int miss = 0;
    bool yes = true;
    for (auto c: sell) {
        auto iter = demond.find(c);
        if (iter == end(demond)) {
            ++extra;
        } else {
            if (iter->second > 0) {
                --(iter->second);
            } else {
                ++extra;
            }
        }
    }
    for (auto entry: demond) {
        if (entry.second != 0) {
            miss += entry.second;
            yes = false;
        }
    }
    if (yes) {
        cout << "Yes " << extra;
    } else {
        cout << "No " << miss;
    }
    cout << "\n";
}