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
    if (sum == 0) {
        cout << 0 << " " << 0 << '\n';
        return 0;
    }
    int bit_counts = 0;
    // 看有多少bits来表达
    for (int i = 1; i <= 32; ++i) {
        // 这儿的意义为低位的i个bit全为1
        // i = 1, (1 << i) - 1 == 1
        // i = 2, 11(二进制)
        unsigned upper = static_cast<unsigned>(1 << i);
        if (sum < upper) {
            bit_counts = i;
            break;
        }
    }
    int zero_counts = 0;
    int one_counts = 0;
    for (int i = 0; i < bit_counts; ++i) {
        int temp = 1 << i;
        if (((temp & sum) >> i) == 0) {
            ++zero_counts;
        } else {
            ++one_counts;
        }
    }
    cout << zero_counts << " " << one_counts << '\n';
    return 0;
}