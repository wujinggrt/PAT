#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto& num: nums) {
        cin >> num;
    }
    // 在 i 的右边的最小值，不包括 i 的值
    vector<int> right_least(n);
    // 最后一位设置为最大的，方便计算，也就是每一个值都小于他
    right_least.back() = INT32_MAX;
    for (int i = n - 2; i >= 0; --i) {
        // 第 i + 1 个数小于它的左边所有最小的
        if (nums[i + 1] < right_least[i + 1]) {
            right_least[i] = nums[i + 1];
        } else {
            right_least[i] = right_least[i + 1];
        }
    }
    // 在 i 的右边的最小值，不包括 i 的值
    vector<int> left_most(n);
    // 最后一位设置为最大的，方便计算，也就是每一个值都小于他
    left_most.front() = INT32_MIN;
    for (int i = 1; i < n; ++i) {
        // 第 i - 1 个数大于它的左边所有最大的
        if (nums[i - 1] > left_most[i - 1]) {
            left_most[i] = nums[i - 1];
        } else {
            left_most[i] = left_most[i - 1];
        }
    }
    vector<int> pivots;
    for (int i = 0; i < n; ++i) {
        if (nums[i] > left_most[i] && nums[i] < right_least[i]) {
            pivots.push_back(nums[i]);
        }
    }
    cout << pivots.size() << "\n";
    for (int i = 0; i < pivots.size(); ++i) {
        if (i != 0) {
            cout << " ";
        }
        cout << pivots[i];
    }
    cout << "\n";
}