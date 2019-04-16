#include <numeric>
#include <functional>
#include <cmath>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    // k 个元素相加
    int n, k, p;
    cin >> n >> k >> p;
    // 确定不会超过多少, 极端情况就是 bound ^ k + 1 ^ k
    auto bound = (int)pow(static_cast<double>(n), 1. / (double)p);
    // 枚举全部的组合？
    // dfs or 枚举 + 剪枝
    // 先从最大的数开始，然后到小的数
    vector<int> sequence;
    int former_accumulation = 0;
    vector<int> tmp_sequence;
    function<void(int, int, int)> dfs = [&] (int max_factor, int sum, int num_factor) {
        // 剪枝
        if (sum > n ||
            ((num_factor == 0) && (sum != n))
        ) {
            return ;
        }
        if (num_factor == 0 && sum == n) {
            if (sequence.empty()) {
                sequence = tmp_sequence;
                former_accumulation = accumulate(begin(tmp_sequence), end(tmp_sequence), 0);
            } else {
                auto sum = accumulate(begin(tmp_sequence), end(tmp_sequence), 0);
                if (sum > former_accumulation) {
                    sequence = tmp_sequence;
                    former_accumulation = sum;
                } else if (sum == former_accumulation) {
                    // largest factor sequence
                    for (int i = 0; i < tmp_sequence.size(); ++i) {
                        if (tmp_sequence[i] > sequence[i]) {
                            sequence = tmp_sequence;
                            break;
                        } else if (tmp_sequence[i] < sequence[i]) { // 需要添加这一个，不然测试点 2 过不去
                            break;
                        }
                    }
                }
            }
        }
        for (int i = max_factor; i >= 1; --i) {
            tmp_sequence.push_back(i);
            dfs(i, sum + pow(i, p), num_factor - 1);
            tmp_sequence.pop_back();
        }
    };
    dfs(bound + 1, 0, k);
    if (sequence.empty()) {
        cout << "Impossible\n";
    } else {
        cout << n << " = ";
        bool first = true;
        for (auto num: sequence) {
            if (first) {
                first = false;
            } else {
                cout << " + ";
            }
            cout << num << "^" << p;
        }
        cout << "\n";
    }
}