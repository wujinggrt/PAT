#include <cstdio>
#include <iostream>
using namespace std;

/* 规律： 比如 1 2 3 4
    1           2           3           4
    1 2         2 3         3 4
    1 2 3       2 3 4       
    1 2 3 4 

1： 4           0           0           0， 1 * 4 * 1
2： 3           3           0           0， 2 * 3 * 2
3： 2           2           2           0， 3 * 2 * 3
4:  1           1           1           1， 4 * 1 * 4
*/

int main() {
    int n;
    cin >> n;
    double fraction;
    double values = 0.;
    for (int i = 0; i < n; ++i) {
        cin >> fraction;
        values += fraction * (n - i) * (i + 1);
    }
    printf("%.2f\n", values);
    return 0;
}