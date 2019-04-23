#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

struct Stu {
    string name;
    int tall;
};

int main(){
    int n, k;
    cin >> n >> k;
    vector<Stu> stus(n);
    for (auto& p: stus) {
        cin >> p.name >> p.tall;
    }
    // decreasing
    sort(begin(stus), end(stus), [] (auto l, auto r) {
        if (l.tall != r.tall) {
            return l.tall > r.tall;
        } else {
            return l.name < r.name;
        }
    });
    int col = n / k;
    int padding = n - col * k;
    int stu_pos = 0;
    for (int i = 0; i < k; ++i) {
        // if ... --padding
        int m = col;
        if (padding != 0) {
            ++m;
            --padding;
        }
        // 中靠后
        int pos = m / 2; 
        int shift = 0;
        vector<string> rows(m);
        for (int j = 0; j < m; ++j) {
            rows[pos + shift] = stus[stu_pos].name;
            if (shift >= 0) {
                ++shift;
            }
            shift *= -1;
            ++stu_pos;
        }
        bool first = true;
        for (auto& s: rows) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << s;
        }
        cout << "\n";
    }
}