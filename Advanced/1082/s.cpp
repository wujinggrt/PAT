#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const char* num[] = {
    "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};

// 0 为个，省略
const char* wei[] = {
    "", "Shi", "Bai", "Qian", "Wan", "Yi"
};

int main() {
    string s;
    cin >> s;
    int left = 0;
    // right 指向一组的最后一个元素
    int right = s.size() - 1;
    if (s.front() == '-') {
        cout << "Fu";
        ++left;
    }
    if (left == right) {
        cout << num[s[left] - '0'] << "\n";
        return 0;
    }
    while (left + 4 <= right) {
        right -= 4;
    }
    for (; left < s.size();) {
        bool print_zero = false;
        // 打印关键的wan
        bool print_critical_wei = false;
        for (; left <= right; ++left) {
            if (s[left] == '0') {
                print_zero = true;
            } else {
                if (print_zero) {
                    cout << " ling";
                    print_zero = false;
                }
                // 首位不能输出空格
                if (left > 0) {
                    printf(" ");
                }
                print_critical_wei = true;
                printf("%s", num[s[left] - '0']);
                if (left != right) {
                    // e.g.  10 0000, 1:right - left == 1
                    // left<-||-> right
                    // right - left == 1
                    cout << " " << wei[right - left]; 
                }
            }
        }
        // 最后的个为不输出
        if (print_critical_wei && right != s.size() - 1) {
            // left到终点的距离，每四位为Qian+上1,比如
            // 0-3位：1000 1 Qain
            // 4-8: Wan
            // 9: Yi
            auto num_remain = s.size() - 1 - right;
            cout << " " << wei[num_remain / 4 + 3];
        }
        right += 4;
    }
    cout << "\n";
    return 0;
}