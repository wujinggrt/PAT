#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string num;
    cin >> num;
    string doubled;
    doubled.reserve(doubled.size() + 2);
    bool carry = false;
    vector<int32_t> cnt(10, 0);
    for (int32_t i = num.size() - 1; i >= 0; --i) {
        ++cnt[num[i] - '0'];
        auto tmp = static_cast<int32_t>(num[i] - '0') * 2 + (carry ? 1 : 0);
        doubled += static_cast<char>(tmp % 10 + '0');
        if (tmp > 9) {
            carry = true;
        } else {
            carry = false;
        }
    }
    if (carry) {
        doubled += '1';
    }
    vector<int32_t> cnt_doubled(10, 0);
    for (auto& c: doubled) {
        ++cnt_doubled[c - '0'];
    }
    if (cnt == cnt_doubled) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    for_each(rbegin(doubled), rend(doubled), [] (auto& c) {
        cout << c;
    });
    cout << "\n";
}