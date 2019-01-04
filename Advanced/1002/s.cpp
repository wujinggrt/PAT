#include <utility>
#include <list>
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    using polynomial = list<pair<int, double>>;
    polynomial a;
    for (int i = 0; i < n; ++i) {
        int exponent;
        double coefficient;
        cin >> exponent >> coefficient;
        a.emplace_back(exponent, coefficient);
    }
    cin >> n;
    polynomial b;
    for (int i = 0; i < n; ++i) {
        int exponent;
        double coefficient;
        cin >> exponent >> coefficient;
        b.emplace_back(exponent, coefficient);
    }
    polynomial result;
    auto it = result.end();
    auto it_a = a.begin();
    auto it_b = b.begin();
    while (it_a != a.end() && it_b != b.end()) {
        if (it_a->first == it_b->first) {
            result.emplace_back(it_a->first, it_a->second + it_b->second);
            ++it_a;
            ++it_b;
        } else if (it_a->first < it_b->first) {
            result.emplace_back(it_b->first, it_b->second);
            ++it_b;
        } else {
            result.emplace_back(it_a->first, it_a->second);
            ++it_a;
        }
        // 如果系数为0的话，那么就pop掉
        if (static_cast<int>(result.back().second * 10) == 0) {
            result.pop_back();
        }
    }
    while (it_a != a.end()) {
        result.emplace_back(it_a->first, it_a->second);
        ++it_a;
    }
    while (it_b != b.end()) {
        result.emplace_back(it_b->first, it_b->second);
        ++it_b;
    }
    printf("%zu", result.size());
    it = result.begin();
    while (it != result.end()) {
        printf(" %d %.1f", it->first, it->second);
        ++it;
    }
}