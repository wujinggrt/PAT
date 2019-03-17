#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    auto isPrime = [] (int n) {
        if (n < 2) {
            return false;
        }
        if (n == 2 || n == 3) {
            return true;
        }
        for (int i = 2; i < sqrt(n) + 1; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    };
    auto myHash = [] (int key, int size) {
        return key % size;
    };
    while (!isPrime(m)) {
        ++m;
    }
    // 0 represented free
    vector<int> hashSimulator(m, 0);
    vector<int> numSet(n);
    bool first = true;
    for (auto& num: numSet) {
        cin >> num;
        auto pos = myHash(num, m);
        if (first) {
            first = false;
        } else {
            cout << " ";
        }
        if (hashSimulator[pos] == 0) {
            cout << pos;
            hashSimulator[pos] = 1;
        } else {
            int step = 1;
            for (; step < m; ++step) {
                if (hashSimulator[(pos + step * step) % m] == 0) {
                    cout << (pos + step * step) % m;
                    hashSimulator[(pos + step * step) % m] = 1;
                    break;
                }
            }
            if (step == m) {
                cout << "-";
            }
        }
    }
}