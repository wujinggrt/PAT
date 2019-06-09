#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    freopen("i.dat", "r", stdin);
    string d;
    int n;
    cin >> d >> n;
    for (; n-- > 1; ) {
        auto iter = begin(d);
        auto previous = *iter;
        ++iter;
        int num_previous = 1;
        string s{previous};
        for (; iter != end(d); ++iter) {
            if (*iter != previous) {
                s += to_string(num_previous) + *iter;
                num_previous = 0;
                previous = *iter;
            }
            ++num_previous;
        }
        s += to_string(num_previous);
        d = std::move(s);
    }
    cout << d << endl;
}
