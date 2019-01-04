#include <iostream>
#include <string>
using namespace std;

int parse(const char& c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    } else {
        return -1;
    }
}

int main() {
    string s;
    getline(cin, s);
    unsigned sum = 0;
    for (const auto& c: s) {
        auto value = parse(c);
        if (value != -1) {
            sum += value + 1;
        }
    }
    // 题目没有考虑全为符号，sum==0, 1， 0；
    if (sum == 0) {
        // if (s.empty()) {
            cout << 0 << " " << 0 << '\n';
        // } else {
        //     cout << 1 << " " << 0 << '\n';
        // }
        return 0;
    }
    int zero_counts = 0;
    int one_counts = 0;
    while (sum != 0) {
        if (sum % 2 == 1) {
            ++one_counts;
        } else {
            ++zero_counts;
        }
        sum /= 2;
    }
    cout << zero_counts << " " << one_counts << '\n';
    return 0;
}