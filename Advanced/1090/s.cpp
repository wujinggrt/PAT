#include <functional>
#include <vector>
#include <unordered_map>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n;
    double p, r;
    cin >> n >> p >> r;
    vector<int> members_supplier(n);
    for (auto& num: members_supplier) {
        scanf("%d", &num);
    }
    // 使用 map 来加速查找，保存查找过的路径长度
    // 向 idx 的进货路径多长。
    unordered_map<int, int> num_path;
    num_path[-1] = 1;
    int max_length = 0;
    int num_max_retailer = 0;
    // 每回溯一次，增加一层
    // 就算最后是 -1， root， 也要想他进货
    // 申请者向 idx 进货
    function<int(int)> dfs = [&] (int idx) {
        // 没到 root 进货。
        if (idx == -1) {
            return 1;
        } else {
            auto iter = num_path.find(idx);
            int final_len;
            if (iter == end(num_path)) {
                final_len = dfs(members_supplier[idx]) + 1; // 得到向下一层进货的长度
                num_path[idx] = final_len;
            } else {
                final_len = iter->second;
            }
            return final_len;
        }
    };
    for (auto retailer: members_supplier) {
        auto len = dfs(retailer); // 向下一层进货
        if (max_length < len) {
            max_length = len;
            num_max_retailer = 1;
        } else if (max_length == len) {
            ++num_max_retailer;
        }
    }
    for (int i = 0; i < max_length - 1; ++i) { // -1 是因为从 root 进货的时候是原价，不乘以 r + 1.
        p *= 1. + r / 100.;
    }
    printf("%.2f %d\n", p, num_max_retailer);
}