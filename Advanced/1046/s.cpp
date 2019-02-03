#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int32_t n;
    cin >> n;
    vector<int32_t> dis(n + 1);
    dis.front() = 0;
    int32_t total_dis = 0;
    for (int32_t i = 1; i <= n; ++i) {
        int32_t tmp;
        scanf("%d", &tmp);
        total_dis += tmp;
        dis[i] = tmp + dis[i - 1];
    }
    int32_t m;
    cin >> m;
    for (int32_t i = 0; i < m; ++i) {
        int32_t from;
        int32_t to;
        scanf("%d %d", &from, &to);
        auto [f, t] = minmax(from, to);
        int32_t d_forward = dis[t - 1] - dis[f - 1];
        int32_t d_backward = total_dis - d_forward;
        cout << (d_backward < d_forward ? d_backward : d_forward) << "\n";
    }
}