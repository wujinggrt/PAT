#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> original(n);
    vector<int> target(n);
    for (int i = 0; i < n; ++i) {
        cin >> original[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> target[i];
    }
    int index = -1;
    for (int i = 1; i < n; ++i) {
        if (target[i] < target[i - 1]) {
            index = i;
            break;
        }
    }
    // 如果是insertion-sort，那么index之后的没有排序，可以检查他们。
    int is_merge = 0;
    for(int i = index; i < n; ++i) {
        if (target[i] != original[i]) {
            is_merge = 1;
            break;
        }
    }
    if (is_merge == 0) {
        printf("Insertion Sort\n");
        sort(target.begin(), target.begin() + index + 1);
        cout << target[0];
        for (int i = 1; i < n; ++i) {
            cout << " " << target[i];
        }
    }
    else if (is_merge == 1) {
        printf("Merge Sort\n");
        int k = 1;
        bool not_equal = true;
        while (not_equal) {
            // 刷新
            not_equal = false;
            if (!equal(original.begin(), original.end(), target.begin())) {
                not_equal = true;
            }
            k *= 2;
            for (int i = 0; i < n / k; ++i) {
                // 最后一次循环的end就是 k * (n / k)
                sort(original.begin() + i * k, original.begin() + (i + 1) * k); 
            }
            // 剩下的，n / k 余数部分
            // 循环体中 i 取到 n / k 的部分是 original.begin() + (i + 1) * k ，、
            // 但是会有被截断的部分没有取。
            // 所以考虑到 n 不能整除，下面情况: 能整除， k * (n / k) 就是end，不做调整，反之，调整。
            sort(original.begin() + k * (n / k), original.end());
        }
        cout << original[0];
        for (int i = 1; i < n; ++i) {
            cout << " " << original[i];
        }
    }
    cout << '\n';
    return 0;   
}