#include <vector>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    // A 左边 P 的数量
    vector<int> num_P(s.size(), 0);
    // A 右边 T 的数量
    vector<int> num_T(s.size(), 0);
    for (int i = s.size() - 1; i > 0; --i) {
        if (s[i] == 'T') {
            num_T[i - 1] = num_T[i] + 1; // i - 1 左边 P 的数量, i = 0 左边的数量自然是 0， 因为没有
        } else {
            num_T[i - 1] = num_T[i];
        }
    }
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == 'P') {
            num_P[i + 1] = num_P[i] + 1; // i + 1 右边 T 的数量
        } else {
            num_P[i + 1] = num_P[i];
        }
    }
    int ans = 0;
    // 因为 i = 0 | n - 1，结果为 0，没有意义。
    for (int i = 1; i < s.size() - 1; ++i) {
        if (s[i] == 'A') {
            ans = (ans + num_P[i] * num_T[i]) % 1000000007;
        }
    }
    cout << ans << "\n";
}