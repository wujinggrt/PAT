#include <cstdio>
#include <stack>
#include <set>
#include <functional>
#include <iostream>
using namespace std;

int main() {
    int32_t n;
    scanf("%d", &n);
    stack<int32_t> num_stack;
    multiset<int32_t, greater<int32_t>> lower;    
    multiset<int32_t> upper;
    int32_t mid = 0;
    // 保证 mid 总是在*begin(lower)
    function<void()> adjust = [&] () {
        // lower 小了
        if (lower.size() < upper.size()) {
            lower.insert(*begin(upper));
            upper.erase(begin(upper));
        // lower 大了
        } else if (lower.size() > upper.size() + 1) {
            upper.insert(*begin(lower));
            lower.erase(begin(lower));
        }
        mid = *begin(lower);
    };
    char function_name[20];
    for (int32_t i = 0; i < n; ++i) {
        scanf("%s", function_name);
        if (function_name[1] == 'o') {
            if (num_stack.empty()) {
                printf("Invalid\n");
            } else {
                printf("%d\n", num_stack.top());
                if (num_stack.top() > mid) {
                    upper.erase(upper.find(num_stack.top()));
                } else {
                    lower.erase(lower.find(num_stack.top()));
                }
                num_stack.pop();
                if (num_stack.empty()) {
                    mid = 0;
                } else {
                    adjust();
                }
            }
        } else if (function_name[1] == 'e') {
            if (num_stack.empty()) {
                printf("Invalid\n");
            } else {
                printf("%d\n", mid);
            }
        } else {
            int32_t num;
            scanf("%d", &num);
            num_stack.push(num);
            if (mid > num) {
                lower.insert(num);
            } else {
                upper.insert(num);
            }
            adjust();
        }
    }
}