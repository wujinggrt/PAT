#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

string norm[] = {
    "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
    "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"
};

void print_mars(const string& s) {
    int i = stoi(s);
    string mars;
    if (i == 0) {
        cout << norm[0] << "\n";
        return ;
    }
    if (i != 0) {
        int moded = i % 13;
        mars = " " + norm[moded] + mars;
        i /= 13;
    }
    if (i != 0) {
        int moded = i % 13;
        mars = " " + norm[moded + 12] + mars;
        i /= 13;
    }
    if (mars.size() > 4) {
        // 后面是 0 就不显示
        if (mars.substr(5) == norm[0]) { 
            cout << mars.substr(1, 3) << "\n";
        } else {
            cout << mars.substr(1) << "\n";
        }
    } else {
        cout << mars.substr(1) << "\n";
    }
}

void print_nums(const string& s) {
    auto iter_former = find(begin(s), end(s), ' ');
    string former(begin(s), iter_former);
    int num = find(begin(norm), end(norm), former) - begin(norm);
    // 只有一位, 取 <= 最后一个测试点过不了
    // num 也就是 0 - 12
    if (num < 13) { 
        cout << num << "\n";
    } else if (num < 25) {
        int i = (num - 12) * 13;
        if (iter_former != end(s)) {
            string lower_part(iter_former + 1, end(s));
            num = find(begin(norm), end(norm), lower_part) - begin(norm);
            i += num;
        }
        cout << i << "\n";
    }
}

int main() {
    int n;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        if (isdigit(s.front())) {
            print_mars(s);
        } else {
            print_nums(s);
        }
    }
}