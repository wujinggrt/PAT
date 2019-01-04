#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n;
    char c;
    cin >> n >> c;
    int rows = (static_cast<float>(n)) / 2 + 0.5;
    for (int i = 0; i < n; ++i) {
        cout << c;
    }
    cout << '\n';
    for (int i = 0; i < rows - 2; ++i) {
        cout << c;
        for (int j = 0; j < n - 2; ++j) {
            cout << " ";
        }
        cout << c << '\n';
    }
    for (int i = 0; i < n; ++i) {
        cout << c;
    }
    return 0;
}