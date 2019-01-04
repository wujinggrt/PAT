#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<char, int> m;
    char c;
    int count = 0;
    int lack = 0;
    string s;
    cin >> s;
    for (const auto& c: s) {
        ++(m[c]);
        ++count;
    }
    cin >> s;
    for (const auto& c: s) {
        auto it = m.find(c);
        // 短路控制，如果it为end，那么肯定不能访问second，否则崩溃
        // 所以写控制流最好不能用 ||
        if (it != m.end() && it->second != 0) {
            --(it->second);
            --count;
        } else {
            ++lack;
        }
    }
    if (lack == 0) {
        printf("Yes %d\n", count);
    } else {
        printf("No %d\n", lack);
    }
    return 0;
}