#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int32_t m;
    int32_t n;
    int32_t k;
    cin >> m >> n >> k;
    for (int i = 0; i < k; ++i) {
        vector<int32_t> sequences(n);
        stack<int32_t> records;
        for (auto& e: sequences) {
            cin >> e;
        }
        bool is_stack = true;
        for (size_t i = 0; i < n && is_stack; ++i) {
            records.push(sequences[i]);
            int32_t tmp_max = sequences[i];
            while (i + 1 < n && sequences[i + 1] < tmp_max) {
                // 在push之前判断，如果超过5
                // 应该是这儿，超过5的情况考虑不全，应该使用模拟栈来完成。
                // 使用比如7 6 5 4 3 2 1中，遇到7，先push7。然后到1，大于5。
                // 怎么解决呢,原来是之前写成5，而不是m了，现在ac了
                if (records.size() >= m) {
                    is_stack = false;
                    break;
                }
                ++i;
                records.push(sequences[i]);
            }
            // check 降序
            int32_t tmp_val = -1;
            while (!records.empty() && is_stack) {
                if (tmp_val < records.top()) {
                    tmp_val = records.top();
                    records.pop();
                } else {
                    is_stack = false;
                    break;
                }
            }
        }
        cout << (is_stack ? "YES\n" : "NO\n");
    }
}