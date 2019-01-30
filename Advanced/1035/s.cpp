#include <vector>
#include <iostream>
using namespace std;

struct Account {
    string name;
    string passwd;
};

int main() {
    int32_t n;
    cin >> n;
    vector<Account> accounts(n);
    for (auto& e: accounts) {
        cin >> e.name >> e.passwd;
    }
    int32_t cnt = 0;
    vector<size_t> modified_idx;
    for (size_t i = 0; i < n; ++i) {
        bool modified = false;
        for (auto& c: accounts[i].passwd) {
            switch (c) {
                case '1':
                    modified = true;
                    c = '@';
                    break;
                case '0':
                    modified = true;
                    c = '%';
                    break;
                case 'l':
                    modified = true;
                    c = 'L';
                    break;
                case 'O':
                    modified = true;
                    c = 'o';
                    break;
            }
        }
        if (modified) {
            ++cnt;
            modified_idx.push_back(i);
        }
    }
    if (cnt == 0) {
        if (n == 1) {
            cout << "There is 1 account and no account is modified\n"s;
        } else {
            printf("There are %d accounts and no account is modified\n", n);
        }
    } else {
        cout << cnt << "\n";
        for (auto& e: modified_idx) {
            cout << accounts[e].name << " " << accounts[e].passwd << "\n";
        }
    }
}