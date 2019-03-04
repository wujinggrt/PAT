#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

struct Mooncake {
    double amount;
    double total_price;
    double unit_price;
};

int main() {
    int32_t n;
    int32_t d;
    cin >> n >> d;
    vector<Mooncake> inventory(n);
    for (auto& item: inventory) {
        cin >> item.amount;
    }
    for (auto& item: inventory) {
        cin >> item.total_price;;
    }
    for (auto& item: inventory) {
        item.unit_price = item.total_price / item.amount;
    }
    sort(begin(inventory), end(inventory), [] (const auto& lhs, const auto& rhs) {
        return lhs.unit_price > rhs.unit_price;
    });
    double profit = 0.;
    for (const auto& item: inventory) {
        if (d != 0) {
            if (d >= item.amount) {
                d -= item.amount;
                profit += item.total_price;
            } else {
                // profit += item.total_price * (static_cast<double>(d) / item.amount);
                profit += static_cast<double>(d) * item.unit_price;
                d = 0;
                break;
            }
        } else {
            break;
        }
    }
    printf("%.2f\n", profit);
}