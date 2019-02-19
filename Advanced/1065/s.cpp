#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int32_t t;
    cin >> t;
    for (int32_t i = 1; i <= t; ++i) {
        int64_t a;
        int64_t b;
        int64_t c;
        bool result = false;
        cin >> a >> b >> c;
        int64_t overflow_sum = a + b;
        // 两个overflow的case
        if (a > 0 && b > 0 && overflow_sum <= 0) { // 大于这个long long能够表示
            result = true;
        } else if (a < 0 && b < 0 && overflow_sum >= 0) { // 小于long long能够表示
            result = false;
        // 一下两个没有overflow的case
        } else if (overflow_sum > c) {
            result = true;
        } else {
            result = false;
        }
        printf("Case #%d: %s\n", i, result ? "true" : "false");
    }
}