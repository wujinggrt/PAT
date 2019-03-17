#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.get();
    vector<string> lines(n);
    for (auto& line: lines) {
        getline(cin, line);
    }
    auto iter = crbegin(lines.front());
    int num = 0;
    string suffix;
    suffix += *iter;
    bool kuchigue = all_of(begin(lines), end(lines), [&] (const auto& e) {
        if (e.size() < suffix.size()) {
            return false;
        }
        return e.substr(e.size() - suffix.size()) == suffix;
    });
    if (!kuchigue) {
        cout << "nai\n";
    } else {
        // 如果只有最后一个char相同，那么这个循环需要处理
        do {
            ++num;
            ++iter;
            // 这儿在最后，可能被跳过了
            if (iter == crend(lines.front())) {
                break;
            }
            suffix = *iter + suffix;
            kuchigue = all_of(begin(lines), end(lines), [&] (const auto& e) {
                if (e.size() < suffix.size()) {
                    return false;
                }
                return e.substr(e.size() - suffix.size()) == suffix;
            });
        } while (kuchigue);
        cout << lines.front().substr(lines.front().size() - num) << "\n";
    }
}