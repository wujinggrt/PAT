#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 考虑还不全
auto cmp(const string& l, const string& r) -> bool {
    if (l.size() == r.size()) {
        return l < r;
    }
    string smaller;
    string bigger;
    if (l.size() < r.size()) {
        smaller = l;
        bigger = r;
    } else {
        smaller = r;
        bigger = l;
    }
    string partial(begin(bigger), begin(bigger) + smaller.size());
    auto iter = begin(bigger) + smaller.size();
    auto iter_front = begin(bigger);
    // 如果前部分相等，也就是小的是子串
    if (partial == smaller) {
        while (iter != end(bigger)) {
            while (iter_front != iter) {
                if (*iter == *iter_front) {
                    ++iter_front;
                } else {
                    return *iter < *iter_front;
                }
            }
            ++iter;
        }
        // 串是一个连串"2222"和"2222222"这种,无论谁前谁后都不影响了，但是为了效率，把它放在前面
        return true;
    } else {
        return l < r;
    }
}

int main() {
    int32_t n;
    cin >> n;
    vector<string> segments(n);
    for (auto& e: segments) {
        cin >> e;
    }
    // 如果两个相等，但是
    auto another_cmp = [] (auto& l, auto& r) {
        string tmp1 = l + r;
        string tmp2 = r + l;
        return tmp1 < tmp2;
    };
    sort(begin(segments), end(segments), another_cmp);
    auto iter = begin(segments.front());
    while (*iter == '0') {
        ++iter;
    }
    if (all_of(begin(segments.back()), end(segments.back()), [] (auto& e) {
        return e == '0';
    })) {
        cout << 0 << "\n";
        return 0;
    }
    segments.front().erase(begin(segments.front()), iter);
    for (auto& e: segments) {
        cout << e;
    }
    cout << "\n";
}