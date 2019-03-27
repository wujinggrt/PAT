#include <iostream>
#include <cmath>
#include <utility>
#include <cstdio>
using namespace std;

int64_t gcd(int64_t a, int64_t b) {
    a = abs(a);
    b = abs(b);
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int64_t lcm(int64_t a, int64_t b) {
    int64_t common = gcd(a, b);
    return a * b / common;
}

// 打印分数，分母保证不为0
void print_num(int64_t a, int64_t b) {
    if (b == 0) {
        cout << "Inf";
        return;
    }
    // 这样不行，越界
    // bool negative = false;
    // if (a * b < 0) {
    //     negative = true;
    // }    int sign = 1;
    if (a < 0) {
        sign *= -1;
    }
    if (b < 0) {
        sign *= -1;
    }
    a = abs(a);
    b = abs(b);
    auto common = gcd(a, b);
    a /= common;
    b /= common;
    int64_t int_part = a / b;
    a %= b;
    if (sign == -1) {
        cout << "(-";
    }
    if (int_part == 0) {
        if (a == 0) {
            cout << "0";
        } else {
            cout << a << "/" << b;
        }
    } else {
        cout << int_part;
        if (a != 0) {
            cout << " " << a << "/" << b;
        }
    }
    if (sign == -1) {
        cout << ")";
    }
}

int main() {
    pair<int64_t, int64_t> former, latter;
    scanf("%ld/%ld %ld/%ld", &former.first, &former.second, &latter.first, &latter.second);
    int64_t common = lcm(former.second, latter.second);

    int64_t sum_first = former.first * (common / former.second) + latter.first * (common / latter.second);
    print_num(former.first, former.second);
    cout << " + ";
    print_num(latter.first, latter.second);
    cout << " = ";
    print_num(sum_first, common);
    cout << "\n";

    int64_t diff_first = former.first * (common / former.second) - latter.first * (common / latter.second);
    print_num(former.first, former.second);
    cout << " - ";
    print_num(latter.first, latter.second);
    cout << " = ";
    print_num(diff_first, common);
    cout << "\n";

    int64_t product_first = former.first * latter.first;
    int64_t product_second = former.second * latter.second;
    print_num(former.first, former.second);
    cout << " * ";
    print_num(latter.first, latter.second);
    cout << " = ";
    print_num(product_first, product_second);
    cout << "\n";

    int64_t quotient_first = former.first * latter.second;
    int64_t quotient_second = former.second * latter.first; // 可能为负数
    print_num(former.first, former.second);
    cout << " / ";
    print_num(latter.first, latter.second);
    cout << " = ";
    print_num(quotient_first, quotient_second);
    cout << "\n";
}