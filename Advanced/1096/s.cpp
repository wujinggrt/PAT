#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int max_factor = static_cast<int>(sqrt(n) + 1);
    int max_num = 0;
    int max_start = 0;
    for (int i = 2; i <= max_factor; ++i) {
        int tmp_num = 1;
        int j = i;
        for (; j <= max_factor; ++j) {
            tmp_num *= j;
            // j 不是乘数因子 factor
            if (n % tmp_num != 0) {
                break;
            }
        }
        if (j - i > max_num){
            max_num = j - i;
            max_start = i;
        }
    }
    if (max_start == 0) {
        cout << 1 << "\n" << n << "\n";
    } else {
        cout << max_num << "\n";
        for (int i = 0; i < max_num; ++i) {
            if (i != 0) {
                cout << "*";
            }
            cout << (max_start + i);
        }
        cout << "\n";
    }
}