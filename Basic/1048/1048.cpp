#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string a;
    cin >> a;
    string b;
    cin >> b;

    if (a.size() > b.size()) {
        auto offset = a.size() - b.size();
        b = string(offset, '0') + b;
    } else if (a.size() < b.size()) {
        auto offset = b.size() - a.size();
        a = string(offset, '0') + a;
    }

    vector<int> r;
    r.reserve(b.size());

    int count = 1;
    for (int i = a.size() - 1; i >= 0; --i, ++count) {
        // odd
        if (count % 2 == 1) {
            int v = (a[i] - '0') + (b[i] - '0');
            r.push_back(v % 13);
        } else {
            int v = b[i] - a[i];
            r.push_back(
                (v < 0 ? v + 10 : v)
            );
        }
    }
    if (r.empty()) {
        cout << '\n';
    }else {
        for (int k = r.size() - 1; k < r.size(); --k) {
            switch (r[k]) {
                case 10:
                    cout << "J";
                    break;
                case 11:
                    cout << "Q";
                    break;
                case 12:
                    cout <<"K";
                    break;
                default:
                    cout << r[k];
                    break;
            }
        }
        cout <<'\n';
    }
    return 0;
}