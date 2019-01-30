#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int32_t max_cnt = 1;
    for (size_t i = 0; i < s.size(); ++i) {
        auto iter_backward = begin(s) + i;
        auto iter_forward = iter_backward + 1;
        if (*iter_backward != *iter_forward ) {
            if (iter_backward != begin(s)) {
                // a b c 不可能对称
                if (*(iter_backward - 1) != *iter_forward) {
                    continue;
                } else {
                // a b a
                    --iter_backward;
                }
            } else {
                continue;
            }
        }
        // else, case a a
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
        if (tmp_cnt > max_cnt) {
            max_cnt = tmp_cnt;
        }
    }
    cout << max_cnt << "\n";;
}