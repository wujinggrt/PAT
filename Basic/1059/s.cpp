#include <cmath>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>
#include <vector>
using namespace std;

bool is_prime(unsigned long n) {
    if (n <= 3) {
        return n > 1;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return false;
    } else {
        // 从5开始判断复杂的循环
        for (unsigned i = 5; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}

struct Record {
    int award;
    bool accessed;
};

int main() {
    int n;
    cin >> n;
    unordered_map<string, Record> m(n);
    pair<string, Record> champion{"", {0, false}};
    cin >> champion.first;
    m.insert(champion);
    for (int i = 2; i <= n; ++i) {
        pair<string, Record> student{"", {0, false}};
        cin >> student.first;
        if (is_prime(i)) {
            student.second.award = 1;
        } else {
            student.second.award = 2;
        }
        m.insert(std::move(student));
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        string id;
        cin >> id;
        auto it = m.find(id);
        cout << id << ": ";
        if (it != m.end()) {
            if (it->second.accessed) {
                cout <<"Checked\n";
            } else {
                switch (it->second.award) {
                    case 0:
                        cout << "Mystery Award\n";
                        break;
                    case 1:
                        cout << "Minion\n";
                        break;
                    case 2:
                        cout << "Chocolate\n";
                        break;
                }
                it->second.accessed = true;
            }
        } else {
            cout << "Are you kidding?\n";
        }
    }
    return 0;
}