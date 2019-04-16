#include <cstdio>
#include <iostream>
#include <string>
#include <functional>
#include <cctype>
#include <algorithm>
using namespace std;

bool Legal(const string& s) {
    int num_dot = 0;
    int after_dot = 0;
    // 使用这个变量防止 - 出现两次
    bool positive = true;
    for (auto c: s) {
        if (c == '-' && positive) {
            positive = false;
        } else if (c == '.') {
            ++num_dot;
            if (num_dot > 1) {
                // 出现了两个 . 或者以上
                return false;
            }
        } else if (!isdigit(c)) {
            return false;
        } else {
            if (num_dot > 0) {
                ++after_dot;
                if (after_dot > 2) {
                    return false;
                }
            }
        }
    }
    double num = stod(s);
    if (num >= -1000. && num <= 1000.) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    double nums = 0.;
    int num_illegal = 0;
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;
        if (Legal(tmp)) {
            nums += stod(tmp);
        } else {
            cout << "ERROR: " << tmp << " is not a legal number\n";
            ++num_illegal;
        }
    }
    if (n == num_illegal) {
        cout << "The average of 0 numbers is Undefined\n";
    } else {
        cout << "The average of " << (n - num_illegal) << (n == num_illegal + 1 ? " number" : " numbers") << " is ";
        printf("%.2f\n", nums / (double)(n - num_illegal));
    }
}