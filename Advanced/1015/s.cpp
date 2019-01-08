#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long to_radix_reversed(long long n, long long radix) {
    long long ret = 0;
    while (n > 0) {
        ret = ret * 10 + n % radix;
        n /= radix;
    }
    return ret;
}

bool is_prime(int n) {
    if (n == 1) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    while (true) {
        string prime;
        long long radix;
        cin >> prime;
        if (prime.front() == '-') {
            break;
        }
        cin >> radix;
        auto parsed = stoll(prime);
        auto reversed = to_radix_reversed(parsed, radix);
        auto reversed_radix_10 = stoll(to_string(reversed), nullptr, radix);
        if (is_prime(reversed_radix_10) && is_prime(stoll(prime))) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}