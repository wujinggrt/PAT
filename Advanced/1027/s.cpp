#include <algorithm>
#include <iostream>
using namespace std;

static const string radix{"0123456789ABC"};

int main() {
    int32_t r;
    int32_t g;
    int32_t b;
    cin >> r >> g >> b;
    auto decode = [] (auto color) -> string {
        if (color == 0) {
            return "00";
        }
        string ret;
        while (color != 0) {
            size_t n = color % 13;
            ret += radix[n];
            color /= 13;
        }
        return ret;
    };
    cout << "#";
    string decoded_r = decode(r);
    string decoded_g = decode(g);
    string decoded_b = decode(b);
    auto printer = [] (const auto& str) {
        if (str.size() == 1) {
            cout << '0';
        }
        for (auto iter = rbegin(str); iter != rend(str); ++iter) {
            cout << *iter;
        }
    };
    printer(decoded_r);
    printer(decoded_g);
    printer(decoded_b);
}