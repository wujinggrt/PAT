#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

static int values[256];

void init_values() {
    for (unsigned char i = '0'; i <= '9'; ++i) {
        values[i] = i - '0';
    }
    for (int i = 'A'; i <= 'Z'; ++i) {
        values[i] = 10 + (i - 'A');
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        values[i] = 10 + (i - 'a');
    }
}

// 如果有c > '9'，那就base > 10
long long decode(const string& s, int base = 10) {
    long long ret = 0;
    for (int i = 0; i < s.size(); ++i) {
        ret = values[s[i]] + ret * base;
    }
    return ret;
}

long long binary_search(const string& s, long long target, long long low, long long high) {
    long long mid = low;
    while (low <= high) {
        mid = (low + high) / 2;
        auto decoded = decode(s, mid);
        if (decoded < 0 || decoded > target) {
            high = mid - 1;
        } else if (decoded < target) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    string n1;
    string n2;
    init_values();
    cin >> n1 >> n2;
    int tag;
    long long radix;
    cin >> tag >> radix;
    long long decoded_num = 0;
    string another;
    if (tag == 1) {
        decoded_num = decode(n1, radix);
        another = n2;
    } else if (tag == 2) {
        decoded_num = decode(n1, radix);
        another = n1;
    }
    auto it = max_element(another.begin(), another.end());
    long long max_num = values[*it];
    auto min_radix = max_num < 2 ? 2 : max_num + 1;
    auto max_radix = max(min_radix, decoded_num);
    auto ret = binary_search(another, decoded_num, min_radix, max_radix);
    if (ret == -1) {
        printf("Impossible\n");
    } else {
        printf("%lld\n", ret);
    }
}