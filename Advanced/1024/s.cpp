#include <iostream>
#include <algorithm>
using namespace std;

string str_plus(const string& l, const string& r) {
    string ret;
    ret.reserve(l.size() + 1);
    bool carry = false;
    auto it_l = rbegin(l);
    auto it_r = rbegin(r);
    for ( ; ; ) {
        if (it_l == rend(l) || it_r == rend(r)) {
            break;
        }
        auto n = static_cast<int32_t>(*it_l - '0') +
                 static_cast<int32_t>(*it_r - '0') +
                 (carry ? 1 : 0);
        ret += static_cast<char>(n % 10 + '0');
        if (n > 9) {
            carry = true;
        } else {
            carry = false;
        }
        ++it_l;
        ++it_r;
    }
    if (carry) {
        ret += '1';
    }
    reverse(begin(ret), end(ret));
    return ret;
}

int main() {
    string n;
    int32_t k;
    cin >> n >> k;
    int32_t steps = 0;
    bool succeed = false;
    for ( ; ; ++steps) {
        string reversed_n(rbegin(n), rend(n));
        if (n == reversed_n || steps == k) {
            succeed = true;
            break;
        }
        n = str_plus(n, reversed_n);
    }
    cout << n << "\n";
    cout << (succeed ? steps : k) << "\n";
}