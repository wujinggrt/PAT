#include <functional>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.size() < 4) {
        string padding(4 - s.size(), '0');
        s = padding + s;
    }
    // 总是保证被减数大
    function<string(const string&, const string&)> string_minus = 
        [] (const string& minuend, const string& subtrahend) {
            auto iter_minuend = crbegin(minuend);
            auto iter_subtrahend = crbegin(subtrahend);
            string ret;
            ret.reserve(4);
            int32_t borrow = 0;
            for (; iter_minuend != crend(minuend);) {
                int32_t num = *iter_minuend - borrow - *iter_subtrahend;
                if (num < 0) {
                    borrow = 1;
                    num += 10;
                } else {
                    borrow = 0;
                }
                ret += static_cast<char>(num + '0');
                ++iter_minuend;
                ++iter_subtrahend;
            }
            return string(crbegin(ret), crend(ret));
    };
    do {
        sort(begin(s), end(s));
        string former = s;
        string latter(crbegin(s), crend(s));
        s = string_minus(latter, former);
        cout << latter << " - " << former << " = " << s + "\n";
    } while (s != "0000"s && s != "6174"s);
}