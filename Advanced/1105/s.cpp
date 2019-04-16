#include <cmath>
#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& num: nums) {
        cin >> num;
    }
    sort(begin(nums), end(nums), std::greater<int>());
    int m = n;
    int min_diff = n - 1;
    for (int i = 1; i <= (n / 2) + 1; ++i) {
        // i * (n / i ) == n
        int j = n / i;
        if (i * j == n) {
            if (j >= i && j - i < min_diff) {
                min_diff = j - i;
                m = j;
            } 
        }
    }
    vector<vector<int>> mat(m, vector<int>(n / m, 0));
    int bottom_bound = m;
    int right_bound = n / m;
    int left_bound = -1;
    int upper_bound = 0;
    // 0 右， 1 下， 2  左， 3 上
    int direction = 0;
    int j = 0;
    int k = 0;
    for (int i = 0; i < n; ) {
        switch (direction) {
            case 0:
                while (k < right_bound) {
                    mat[j][k] = nums[i];
                    ++k;
                    ++i;
                }
                --right_bound;
                --k; // 调整回来
                ++j; // 下一行
                direction = (direction + 1) % 4;
                break;
            case 1:
                while (j < bottom_bound) {
                    mat[j][k] = nums[i];
                    ++j;
                    ++i;
                }
                --bottom_bound;
                --j;
                --k;
                direction = (direction + 1) % 4;
                break;
            case 2:
                while (k > left_bound) {
                    mat[j][k] = nums[i];
                    --k;
                    ++i;
                }
                ++left_bound;
                ++k;
                --j;
                direction = (direction + 1) % 4;
                break;
            case 3:
                while (j > upper_bound) {
                    mat[j][k] = nums[i];
                    --j;
                    ++i;
                }
                ++upper_bound;
                ++j;
                ++k;
                direction = (direction + 1) % 4;
                break;
        }
    }
    for (auto& row: mat) {
        bool first = true;
        for (auto num: row) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << num;
        }
        cout << "\n";
    }
}