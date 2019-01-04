#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    long r = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == i) {
                continue;
            }
            r += vec[i] * 10 + vec[j];
        }
    }
    cout << r << '\n';
    return 0;
}