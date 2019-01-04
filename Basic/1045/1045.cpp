#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<int> pivots;
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    /* 
        132的简化版

        每次迭代，记录左边最大值（随着i增大，也就是右移，那么更新左边最大值，所以最大最小值总共只用消耗2 * n，时间解决了。），
        
        右边的话，假想成从n-1开始前推，于是得到右边的最小值。此时需要另外一个循环。
        
        按顺序存在stack。如果遇到更小的，通过弹栈和push操作调整栈，使得栈有序。
        那么通过i的前进，就可以弹出stack，查看元素是否有效（是否还在另外一边）。

        但是这题只用知道大和小的就OK了。不用stack.

        当没有符合的时候，输出：
        0\n
        \n
    */
    /*
        i:
        左边最大, left_max[i - 1]; // 不算当前值
        右边最小, right_min[i + 1]

        一个数组，记录一点的左边最大和右边最小
    */
    vector<int> right_min(n);
    right_min[n - 1] = vec[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        right_min[i] = min(vec[i + 1], right_min[i + 1]);
    }
    vector<int> left_max(n);
    left_max[0] = vec[0];
    for (int i = 1; i < n; ++i) {
        left_max[i] = max(vec[i - 1], left_max[i - 1]);
    }
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        if (left_max[i] <= vec[i] && right_min[i] >= vec[i]) {
            flag = true;
        }
        if (flag) {
            pivots.push_back(vec[i]);
        }
    }
    if (pivots.empty()) {
        cout << "0\n";
    } else {
        cout << pivots.size() << '\n';
        sort(pivots.begin(), pivots.end());
        cout << pivots[0];
        for (int i = 1; i < pivots.size(); ++i) {
            cout << " " << pivots[i];
        }
    }
    cout << '\n';
    return 0;
}