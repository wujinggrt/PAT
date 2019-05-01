#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <functional>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    function<bool(int)> is_prime = [] (int num) {
        if (num < 2) {
            return false;
        } else if (num == 2 || num == 3) {
            return true;
        }
        for (int i = 2; i < sqrt(num) + 1; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    };
    vector<string> ids(n);
    unordered_map<string, int> ranklist;
    unordered_set<string> checked;
    for (int i = 0; i < n; ++i) {
        cin >> ids[i];
        ranklist[ids[i]] = i + 1;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        auto iter = ranklist.find(s);
        if (iter == end(ranklist)) {
            cout << s << ": Are you kidding?\n";
        } else {
            // 如果出现过了
            if (!checked.insert(s).second) {
                cout << s << ": Checked\n";
            } else {
                if (iter->second == 1) {
                    cout << s + ": " "Mystery Award\n";
                } else if (is_prime(iter->second)) {
                    cout << s << ": Minion\n";
                } else {
                    cout << s << ": Chocolate\n";
                }
            }
        }
    }
}