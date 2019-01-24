#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

auto decode(uint64_t n, const uint64_t& radix) {
    vector<uint32_t> ret;
    ret.reserve(32);
    while (n != 0) {
        auto tmp = n % radix;
        ret.push_back(tmp);
        n /= radix;
    }
    return ret;
}

int main() {
    string s;
    uint64_t n;
    uint64_t radix;
    cin >> n >> radix;
    auto vec = decode(n, radix);
    reverse(vec.begin(), vec.end());
    bool flag = true;
    if (vec.size() == 1) {
        flag = true;
    } else {
        auto it_clockwise = vec.begin();
        auto it_counter = vec.end() - 1;
        for (; it_clockwise < it_counter; ) {
            if (*it_clockwise != *it_counter) {
                flag = false;
                break;
            }
            ++it_clockwise;
            --it_counter;
        }
    }
    cout << (flag ? "Yes\n" : "No\n");
    cout << vec.front();
    for (uint32_t i = 1; i < vec.size(); ++i) {
        cout << " " << vec[i];
    }
    cout << '\n';
}