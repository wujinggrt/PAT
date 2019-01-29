#include <queue>
#include <iostream>
using namespace std;

int main() {
    int32_t n, m;
    cin >> n;
    queue<int32_t> former;
    for (int32_t i = 0; i < n; ++i)  {
        int32_t num;
        scanf("%d", &num);
        // cin >> num;
        former.push(std::move(num));
    }
    former.push(INT32_MAX);
    cin >> m;
    queue<int32_t> latter;
    int32_t pop_cnt = 0;
    for (int32_t i = 0; i < m; ++i) {
        int32_t num;
        // cin >> num;
        scanf("%d", &num);
        latter.push(std::move(num));
        if (pop_cnt == (n + m - 1) / 2) {
            printf("%d\n", min(former.front(), latter.front()));
            return 0;
        }
        if (latter.front() < former.front()) {
            latter.pop();
        } else {
            former.pop();
        }
        ++pop_cnt;
    }
    latter.push(INT32_MAX);
    // n, m其中之一为0，需要考虑到这种情况，所以有INT32_MAX
    for (; pop_cnt < (n + m - 1) / 2; ++pop_cnt) {
        if (latter.front() < former.front()) {
            latter.pop();
        } else {
            former.pop();
        }
    }
    printf("%d\n", min(former.front(), latter.front()));
}