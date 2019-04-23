#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

bool sureGood[256] = {false};

int main() {
    int k;
    string s;
    cin >> k >> s;
    map<char, bool> m;
    char pre = '#'; // 反正是不会出现的值
    int cnt = 1;
    for (auto c: s) {
        if (c == pre) {
            ++cnt;
        } else {
            // 可能连续好几 n * k 个
            if (cnt % k != 0) {
                sureGood[pre] = true;
            }
            cnt = 1;
        }
        m[c] = cnt % k == 0;
        pre = c;
    }
    // 调整
    for (auto c: s) {
        if (sureGood[c]) {
            m[c] = false;
        }
    }
    // print the broken
    set<char> printed;
    for (auto c: s) {
        if (m[c] && printed.find(c) == end(printed)) {
            cout << c;
            printed.insert(c);
        }
    }
    cout << "\n";
    for (int i = 0; i < s.size(); ++i) {
        cout << s[i];
        if (m[s[i]]) {
            i += k - 1;
        }
    }
    cout << "\n";
}