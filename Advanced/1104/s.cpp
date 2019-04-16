#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> nums(n + 1);
    double ans = 0.;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        ans += nums[i] * i * (n - i + 1);
    }
    // for (auto& num: nums) {
    //     cin >> num;
    // }
    printf("%.2f\n", ans);
    double d1 = 3 * 1.5;
    cout << d1 << "\n";
}