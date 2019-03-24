#include <cstdio>

#include <vector>
#include <utility>
#include <iostream>
using namespace std;

int64_t gcd(int64_t a, int64_t b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int64_t lcm(int64_t a, int64_t b) {
    auto common = gcd(a, b);
    return a * b / common;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int64_t, int64_t>> nums(n);
    for (auto& twin: nums) {
        scanf("%ld/%ld", &(twin.first), &(twin.second));
        auto common = gcd(twin.first, twin.second);
        twin.first /= common;
        twin.second /= common;
    }
    int64_t int_part = 0;
    pair<int64_t, int64_t> ans{0, 1};
    for (auto num: nums) {
        auto common = lcm(ans.second, num.second);
        ans.first *= (common / ans.second);
        num.first *= (common / num.second);
        ans.first += num.first;
        ans.second = common;
    }
    int_part += ans.first / ans.second;
    auto common = gcd(ans.first, ans.second);
    ans.first /= common;
    ans.second /= common;
    ans.first %= ans.second;
    if (int_part == 0) {
        if (ans.first == 0) {
            printf("0\n");
        } else {
            printf("%ld/%ld\n", ans.first, ans.second);
        }
    } else {
        if (ans.first == 0) {
            printf("%ld\n", int_part);
        } else {
            printf("%ld %ld/%ld\n", int_part, ans.first, ans.second);
        }
    }
}