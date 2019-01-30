#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    if (s.empty()) {
        cout << 0 << "\n";
        return 0;
    }
    int32_t max_cnt = 1;
    for (size_t i = 0; i < s.size(); ++i) {
        auto iter_backward = begin(s) + i;
        auto iter_forward = iter_backward + 1;
        int32_t tmp_another = 0;
        // 需要优先考虑 "aba"类型，而不是"aa"类型，
        // 不然比如"111", "a111a"都会被判断为2
        if (
            iter_backward != begin(s) &&
            (*(iter_backward - 1) == *iter_forward)) {
            // case: a b a or aaa
            if (*iter_backward == *iter_forward) {
                auto iter_b = iter_backward;
                auto iter_f = iter_forward;
                for (;;) {
                    if (*iter_b == *iter_f && 
                        iter_b >= begin(s) &&
                        iter_f != end(s)) {
                        ++iter_f;
                        --iter_b;
                    } else {
                        break;
                    }
                }
                tmp_another = iter_f - iter_b - 1;
            }
            --iter_backward;
        } else if (*iter_backward != *iter_forward) {
            // case: a b c
            continue;
        }
        // else, case: a a
        for (;;) {
            if (*iter_backward == *iter_forward && 
                iter_backward >= begin(s) &&
                iter_forward != end(s)) {
                ++iter_forward;
                --iter_backward;
            } else {
                break;
            }
        }
        int32_t tmp_cnt = iter_forward - iter_backward - 1;
        tmp_cnt = (tmp_cnt > tmp_another ? tmp_cnt : tmp_another);
        if (tmp_cnt > max_cnt) {
            max_cnt = tmp_cnt;
        }
    }
    cout << max_cnt << "\n";;
}