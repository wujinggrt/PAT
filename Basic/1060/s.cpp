#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    for (int i = n; i >= 0; ++i) {
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            if (vec[i] <= i) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}