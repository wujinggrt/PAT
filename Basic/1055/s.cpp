#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    if (k == 0 || n == 0) {
        return 0;
    }
    vector<pair<string, int>> vec;
    for (int i = 0; i < n; ++i) {
        string name;
        int tall;
        cin >> name >> tall;
        vec.emplace_back(name, tall);
    }
    sort(vec.begin(), vec.end(), [] (const auto& l, const auto& r) {
        if (l.second != r.second) {
            return l.second > r.second;
        } else {
            // 根据题意：若多人身高相同，则按名字的字典序升序排列。这里保证无重名。
            // 同身高的话，排序按名字字典升序，名字字典顺序小的排前面，即是靠高的人
            return l.first < r.first;
        }
    });
    int students_per_row = n / k;
    int last_row = students_per_row + (n - students_per_row * k);
    for (int j = 0, i = 0; j < k; ++j) {
        int row_counts;
        if (i < last_row) {
            row_counts = last_row;
        } else {
            row_counts = students_per_row;
        }
        /* 
            目前的情况：一个身高排序的vec
            对于buffer，计算出最高位置后，当前最高身高位置，左移1，右移1，左移2，右移2...这样的规律，写入buffer相应的位子
            buffer[tallest] = vec[i], buffer[tallest - 1] = vec[i + 1], buffer[tallest + 1] = vec[i + 2]...
            然后从buffer输出，得到想要的顺序
            比如 0 2 3 1就是保存到buffer的顺序。
            保存到buffer就是
            对于offset就是*（+、-）1，然后自增
        */
        auto tallest_index = row_counts / 2;
        bool left_shift_flag = true;
        vector<string> buffer(row_counts);
        buffer[tallest_index] = vec[i].first;
        int offset = 1;
        for (int x = 1; x < row_counts; ++x) {
            buffer[tallest_index - (left_shift_flag ? offset : -1 * offset)] = vec[i + x].first.c_str();
            left_shift_flag = !left_shift_flag;
            // 没进行完左移一次和右移一次，增加偏移量
            if (left_shift_flag) {
                ++offset;
            }
        }
        cout << buffer[0];
        for (int x = 1; x < buffer.size(); ++x) {
            cout << " " << buffer[x];
        }
        cout << '\n';
        i += row_counts;
    }
    return 0;
}