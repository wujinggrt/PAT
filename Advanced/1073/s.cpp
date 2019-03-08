#include <cstdio>

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    auto iter = begin(s);
    bool positive = *iter == '+';
    ++iter;
    auto numMain = *iter;
    // skip point
    iter += 2;
    auto iterFraction = iter;
    while (*iter != 'E') {
        ++iter;
    }
    string fraction(iterFraction, iter);
    ++iter;
    bool positiveExponent = *iter == '+';
    ++iter;
    string exponent(iter, end(s));
    int32_t numExponent = stoi(exponent);
    if (numExponent == 0) {
        string s(fraction.size(), '0');
        cout << ("1." + s) + "\n";
        return 0;
    }
    if (positive == false) {
        cout << "-";
    }
    if (positiveExponent) { // 小数点后移
        // 如果指数的值大于小数点的位子，那么就在后面补0
        if (numExponent >= fraction.size()) {
            fraction += string(numExponent - fraction.size(), '0');
        } else {
            // 在合适的地方插入小数点
            iter = begin(fraction);
            iter += numExponent;
            fraction.insert(iter, '.');
        }
        printf("%c%s\n", numMain, fraction.c_str());
    } else { // 小数点前移,numExponent >= 1
        string padding(numExponent - 1, '0');
        printf("0.%s\n", (padding + numMain + fraction).c_str());
    }
}