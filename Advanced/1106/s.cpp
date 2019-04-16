#include <math.h>
#include <functional>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

static const int INF = 0x3f3f3f3f;

int main() {
    int n;
    double p, r;
    cin >> n >> p >> r;
    vector<vector<int>> chains(n);
    for (auto& chain: chains) {
        int k;
        cin >> k;
        chain = vector<int>(k);
        for (int i = 0; i < k; ++i) {
            int j;
            cin >> j;
            chain[i] = j;
        }
    }
    int len_chain = n - 1;
    int num = 0;
    function<void(int, int)> dfs = [&] (int index, int cur_len_chain) {
        bool is_retailer = true;
        for (auto& dis: chains[index]) {
            is_retailer = false;
            dfs(dis, cur_len_chain + 1);
        }
        if (is_retailer) {
            if (cur_len_chain < len_chain) {
                len_chain = cur_len_chain;
                num = 1;
            } else if (cur_len_chain == len_chain) {
                ++num;
            }
        }
    };
    dfs(0, 0);
    for (int i = 0; i < len_chain; ++i) {
        p += p * (r / 100.);
    }
    printf("%.4f %d\n", p, num);
}