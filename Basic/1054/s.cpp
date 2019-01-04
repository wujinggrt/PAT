#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;
    double sum = 0.;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        double result = 0.;
        int point_count = 0;
        int fraction_count = 0;
        bool not_legal = false;
        for (int j = 0; j < s.size(); ++j) {
            char c = s[j];
            // 只有一个负号，且只能在首位
            if (c == '-') {
                if (j == 0) {
                    continue;
                } else {
                    not_legal = true;
                    break;
                }
            // 记录小数点数量，且不能出现两个
            } else if (c == '.') {
                ++point_count;
                // 小数点出现在第一位，或者第二位且前面为-号
                // 小数点出现在最后一位？ 如1.
                if (
                    j == 0 ||
                    (s[0] == '-' && j == 1)
                ) {
                    not_legal = true;
                    break;                    
                }
                continue;
            } else if (
                c < '0' ||
                c > '9'
            ) {
                not_legal = true;
                break;
            } else if (point_count != 0) {
                ++fraction_count;
            }
        }
        if (not_legal) {
            printf("ERROR: %s is not a legal number\n", s.c_str());
            continue;
        }
        try {
            result = stod(s);
        } catch (...) {
            printf("ERROR: %s is not a legal number\n", s.c_str());
            continue;
        }
        if (
            result > 1000 || 
            result < -1000 ||
            fraction_count > 2 ||
            point_count > 1 
        ) {
            printf("ERROR: %s is not a legal number\n", s.c_str());
            continue;
        }
        ++count;
        sum += result;
    }
    if (count == 0) {
        cout << "The average of 0 numbers is Undefined\n";
    } else if (count == 1) {
        printf("The average of %d number is %.2f\n", count, sum / count);
    } else {
        printf("The average of %d numbers is %.2f\n", count, sum / count);
    }
    return 0;
}