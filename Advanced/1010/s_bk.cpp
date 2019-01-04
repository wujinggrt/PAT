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

int main() {
    string n1;
    string n2;
    init_values();
    cin >> n1 >> n2;
    int tag;
    long long radix;
    cin >> tag >> radix;
    long long known = 0;
    string unknown;
    if (tag == 1) {
        known = decode(n1, radix);
        unknown = n2;
    } else if (tag == 2) {
        known = decode(n2, radix);
        unknown = n1;
    }
    auto it = max_element(unknown.begin(), unknown.end());
    long long max_num = values[*it];
    // 最小进制为1能够通过测试
    auto low = max_num + 1;
    auto high = max(low, known);
    long long result = -1;
    while (low <= high) {
        auto mid = (low + high) / 2;
        auto tmp = decode(unknown, mid);
        // 小于 0 为越界
        if (tmp < 0 || tmp > known) {
            high = mid - 1;
        } else if (tmp < known) {
            low = mid + 1;
        } else {
            result = mid;
            break;
        }
    }
    if (result != -1) {
        cout << result << endl;
    } else {
        printf("Impossible\n");
    }
}