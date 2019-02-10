#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

bool is_prime(int64_t n) {
    if (n == 0 || n == 1) {
        return false;
    } else if (n == 2 || n == 3) {
        return true;
    } else {
        for (int64_t i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}

int main(){
    int64_t n;
    int64_t prime_factor = 2;
    bool first = true;
    cin >> n;
    cout << n << "=";
    if (n == 1 ||is_prime(n)) {
        cout << n << "\n";
        return 0;
    }
    while (prime_factor <= n) {
        int32_t exponent = 0;
        while (n % prime_factor == 0) {
            n /= prime_factor;
            ++exponent;
        }
        if (exponent > 0) {
            if (!first) {
                cout << "*";
            }
            if (exponent == 1) {
                cout << prime_factor;
            } else {
                printf("%ld^%d", prime_factor, exponent);
            }
            first = false;
            if (is_prime(n)) {
                cout << "*"<< n << "\n";
                return 0;
            }
        } else {
            ++prime_factor;
            while (!is_prime(prime_factor)) {
                ++prime_factor;
            }
        }
    }
}