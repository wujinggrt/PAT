#include <algorithm>
#include <vector>
#include <cstdio>
#include <functional>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> origin(n);
    vector<int> target(n);
    for (auto& num: origin) {
        cin >> num;
    }
    for (auto& num: target) {
        cin >> num;
    }
    // 这样是错误的...因为负数
    // int former = -1;
    // int diff_pos = 0;
    // for (; diff_pos < n; ++diff_pos) {
    //     if (target[diff_pos] > former) {
    //         former = target[diff_pos];
    //     } else {
    //         break;
    //     }
    // }
    int diff_pos = 0;
    for (int i = 1; i < n; ++i) {
        if (target[i] < target[i - 1]) {
            diff_pos = i;
            break;
        }
    }
    bool is_insertion = true;
    for (int j = diff_pos; j < n; ++j) {
        if (origin[j] != target[j]) {
            is_insertion = false;
            break;
        }
    }
    if (is_insertion) {
        // cout << "Insertion Sort\n";
        // 应该直接使用
        // sort(begin(target), begin(target) + i);
        // auto key = target[i];
        // int j = i - 1;
        // for (; j >= 0 && (target[j] > key); --j) {
        //     target[j + 1] = target[j];
        // }
        // target[j + 1] = key;
        // bool first = true;
        // for (auto num: target) {
        //     if (first) {
        //         first = false;
        //     } else {
        //         cout << " ";
        //     }
        //     cout << num;
        // }
        // cout << "\n";

       printf("Insertion Sort\n");
        sort(target.begin(), target.begin() + diff_pos + 1);
        cout << target[0];
        for (int i = 1; i < n; ++i) {
            cout << " " << target[i];
        }

    } else {
        cout << "Merge Sort\n";
        // [left, mid], (mid, right]
        // 排序一块
        function<void(int, int)> merge = [&] (int left, int right) {
            if (left >= right) {
                return ;
            }
            vector<int> buffer(begin(origin) + left, begin(origin) + right + 1);
            int mid = (left + right) / 2;
            int left_bound = mid - left + 1; // 左半部分大小
            int right_bound = buffer.size(); // 右半部分大小，总共元素
            int i = 0;
            int j = left_bound;
            for (; i < left_bound && j < right_bound;) {
                if (buffer[i] < buffer[j]) {
                    origin[left] = buffer[i];
                    ++i;
                } else {
                    origin[left] = buffer[j];
                    ++j;
                }
                ++left;
            }
            for (; i < left_bound; ++i) {
                origin[left] = buffer[i];
                ++left;
            }
            for (; j < right_bound; ++j) {
                origin[left] = buffer[j];
                ++left;
            }
        };
        bool not_equal = true;
        // i 为每一趟归并的长度
        // i 能够取到 n 
        for (int i = 2; not_equal; i *= 2) { 
            // 每次进行一趟归并
            if (origin == target) {
                not_equal = false;
            }
            int interval = n / i;
            for (int j = 0; j < interval; ++j) { // 向下取整
                int left = j * i;
                // int right = ((left + i - 1) < n ? left + i - 1 : n - 1);
                int right = (j + 1) * i - 1;
                // 最后的一位小于2，也就是j是最后一位，只有一个，那就break了。
                // 越界保护
                // if (right <= left) { 
                //     break;
                // }
                if (right >= n) {
                    break;
                }
                merge(left, right);
            }
            merge(i * interval, n - 1);
        }
        bool first = true;
        for (auto num: origin) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << num;
        }
        
        // printf("Merge Sort\n");
        // int k = 1;
        // bool not_equal = true;
        // while (not_equal) {
        //     // 刷新
        //     not_equal = false;
        //     if (origin != target) {
        //         not_equal = true;
        //     }
        //     k *= 2;
        //     for (int i = 0; i < n / k; ++i) {
        //         sort(origin.begin() + i * k, origin.begin() + (i + 1) * k); 
        //     }
        //     sort(origin.begin() + k * (n / k), origin.end());
        // }
        // cout << origin[0];
        // for (int i = 1; i < n; ++i) {
        //     cout << " " << origin[i];
        // }
    }
    cout << '\n';
}