#include <vector>
#include <iostream>
using namespace std;

int main() {
    int32_t n;
    int32_t m;
    cin >>n >> m;
    vector<int32_t> chain(n);
    for (auto& e: chain) {
        cin >> e;
    }
    vector<pair<size_t, size_t>> diamonds;
    size_t i = 0;
    size_t j = 0;
    int32_t diff = INT32_MAX;
    int32_t tmp_sum = 0;
    for (; j < n; ++j) {
        // printf("Outer for:%zu %zu tmp_sum:%d\n", i, j, tmp_sum);
        tmp_sum += chain[j];
        // 可能移动i
        if (tmp_sum == m) {
            diff = 0;
            diamonds.emplace_back(i, j);
            // printf("After if:%zu %zu tmp_sum:%d\n", i, j, tmp_sum);
        } else if (tmp_sum > m) { // 移动i
            for (;;) {
                if (tmp_sum - m <= diff) {
                    if (tmp_sum - m < diff) {
                        diamonds.clear();
                        diff = tmp_sum - m;
                    }
                    diamonds.emplace_back(i, j);
                }
                tmp_sum -= chain[i];
                ++i;
                if (tmp_sum < m) {
                    --i;
                    tmp_sum += chain[i];
                    break;
                }
                // printf("After else if:%zu %zu tmp_sum:%d\n", i, j, tmp_sum);
            }
        }
    }
    for (const auto& e: diamonds) {
        cout << e.first + 1 << "-"<< e.second + 1 << "\n";
    }
}