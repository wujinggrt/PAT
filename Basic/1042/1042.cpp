#include <unordered_map>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

bool is_digit(const char& c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char to_lower(const char& c) {
    return c < 'a' ? 'a' + (c - 'A') : c;
}

int main() {
    char c;
    unordered_map<char, int> statistics;
    int max_count = 0;
    char max_char = 'A';
    while (cin >> c) {
        if (is_digit(c)) {
            ++statistics[to_lower(c)];
        }
    }
    for (const auto& e: statistics) {
        if (e.second > max_count) {
            max_char = e.first;
            max_count = e.second;
        } else if (e.second == max_count && e.first < max_char) {
            max_char = e.first;
            max_count = e.second;
        }
    }
    cout << max_char << " " << max_count;
    return 0;
}