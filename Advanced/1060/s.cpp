#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

string convert_float(int32_t radix, const string& s) {
    if (s == "0"s) {
        return "0." + string(radix, '0') + "*10^0"s;
    }
    int32_t exponent = 0;
    string nums;
    nums.reserve(s.size());
    bool before_point = true;
    bool all_zero = true;
    for (auto c: s) {
        if (c == '.') {
            before_point = false;
            continue;
        }
        nums += c;
        // 从第一个不为0的数开始append到nums，全为0的case已经视为特殊情况
        if (c != '0') {
            all_zero = false;
        }
        if (before_point) {
            ++exponent;
        }
    }
    // 移除前面的0，每次移除一个，就exponent--
    auto front_zero = nums.find_first_not_of('0');
    if (front_zero != string::npos) {
        exponent -= front_zero;
        nums.erase(begin(nums), begin(nums) + front_zero);
    }
    // erase
    if (nums.size() > radix) {
        nums.erase(begin(nums) + radix, end(nums));
    // append 0.
    } else if (nums.size() < radix) {
        nums += string(radix - nums.size(), '0');
    }
    // case 00.00
    if (all_zero) {
        exponent = 0;
    }
    string ret = "0."s + nums + "*10^"s + to_string(exponent);
    return ret;
}

int main() {
    int32_t n;
    string a;
    string b;
    bool is_equal = true;
    cin >> n >> a >> b;
    // 去掉前面的0
    // 00000000120 0000123
    // 0000000.01 0000.003，消掉*0.中的*
    auto adjust = [] (auto& s) {
        if (s.size() > 1 && s[0] == '0') {
            auto front = s.find_first_not_of('0');
            // all zero
            if (front == string::npos) {
                s = "0"s;
            } else {
                // with point
                if (front != string::npos && s[front] == '.') {
                    front--;
                }
                s = string(begin(s) + front, end(s));
            }
        }
    };
    adjust(a);
    adjust(b);
    auto point_pos_a = a.find('.');
    if (point_pos_a == string::npos) {
        point_pos_a = a.size();
    }
    auto point_pos_b = b.find('.');
    if (point_pos_b == string::npos) {
        point_pos_b = b.size();
    }
    a = convert_float(n, a);
    b = convert_float(n, b);
    if (a == b) {
        cout << "YES "s + a;
    } else {
        cout << "NO "s + a + " " + b;
    }
    cout << "\n";
}