#include <cstdio>
#include <cctype>
#include <sstream>
#include <iostream>
using namespace std;

// 由于到过来，不可能 0 在首位，必有 b 的 size() <= a.size()
string string_plus(string a, const string& b) {
    auto iter = rbegin(a);
    bool carry = false;
    auto iter_b = crbegin(b);
    for (; iter_b != crend(b); ) {
        int sum = (*iter - '0') + (*iter_b - '0') + (carry ? 1 : 0);
        *iter = sum % 10 + '0';
        carry = sum > 9;
        ++iter;
        ++iter_b;
    }
    if (carry) {
        return '1' + a;
    }
    return a;
}

int main() {
    freopen("i2.dat", "r", stdin);
    string num;
    cin >> num;
    if (num == string(rbegin(num), rend(num))) {
        cout << num << " is a palindromic number.\n";
        return 0;
    }
    for (int i = 0; i < 10; ++i) {
        string bstr{crbegin(num), crend(num)};
        // align
        bstr = string(num.size() - bstr.size(), '0') + bstr;
        string res = string_plus(num, bstr);
        cout << num << " + " << bstr << " = " << res << '\n';
        // 奇数的 case 不需要包含中间的那个 char
        if (res.substr(0, res.size() / 2) == string(rbegin(res), rbegin(res) + res.size() / 2)) {
            cout << res << " is a palindromic number.\n";
            return 0;
        }
        num = std::move(res);
    }
    cout << "Not found in 10 iterations.\n";
}
