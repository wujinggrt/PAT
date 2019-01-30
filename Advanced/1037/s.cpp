#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int32_t n_c;
    cin >> n_c;
    vector<int32_t> coupons(n_c);
    for (auto& e: coupons) {
        cin >> e;
    }
    int32_t n_p;
    cin >> n_p;
    vector<int32_t> products(n_p);
    for (auto& e: products) {
        cin >> e;
    }
    auto cmp = [] (const auto& l, const auto& r) {
        return l > r;
    };
    sort(begin(coupons), end(coupons), cmp);
    sort(begin(products), end(products), cmp);
    auto finder = [] (const auto& e) {
        return e <= 0;
    };
    auto iter_c_zero = find_if(begin(coupons), end(coupons), finder);
    auto iter_p_zero = find_if(begin(products), end(products), finder);
    int32_t total = 0;
    auto iter_c = begin(coupons);
    auto iter_p = begin(products);
    // 正数部分，正序遍历
    for (;;) {
        if (iter_c < iter_c_zero && iter_p < iter_p_zero) {
            total += *iter_c * *iter_p;
            ++iter_c;
            ++iter_p;
        } else {
            break;
        }
    }
    // 负数部分
    iter_c = end(coupons) - 1;
    iter_p = end(products) - 1;
    for (;;) {
        if (iter_c >= iter_c_zero && iter_p >= iter_p_zero) {
            total += *iter_c * *iter_p;
            --iter_c;
            --iter_p;
        } else {
            break;
        }
    }
    cout << total << "\n";
}