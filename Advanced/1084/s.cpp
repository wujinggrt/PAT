#include <cstdio>
#include <cctype>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    string origin;
    string typed;
    cin >> origin >> typed;
    // 坏的就是true
    unordered_map<char, bool> record;
    for (auto c: origin) {
        if (isalpha(c)) {
            record[toupper(c)] = true;
        } else {
            record[c] = true;
        }
    }
    // 扫描输入的，找出坏的
    // j 指向坏的
    // 坏的就是true
    for (auto c: typed) {
        if (isalpha(c)) {
            c = toupper(c);
        }
        if (record[c]) {
            record[c] = false;
        }
    }
    for (auto c: origin) {
        // 如果是坏的，print它，然后在设置为true，以后就不访问它了
        if (isalpha(c)) {
            c = toupper(c);
        }
        if (record[c]) {
            cout << c;
            record[c] = false;
        }
    }
    cout << "\n";
}