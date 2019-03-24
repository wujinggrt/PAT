#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int64_t n, p;
    cin >> n >> p;
    vector<int64_t> seq(n);
    for (int64_t& num: seq) {
        cin >> num;
    }
    sort(begin(seq), end(seq));
    int64_t perfect = 1;
    for (int64_t i = 0; i < seq.size(); ++i) {
        // 对每一位元素审查perfect
        // 偏移，最大的元素必然是最后面一位
        // i + perfect - 1 就是最大的一位
        for (; 
            (i + perfect - 1 < seq.size()) && 
                (seq[i + perfect - 1] <= seq[i] * p); 
            ++perfect) {
        }
    }
    cout << (perfect - 1) << "\n";
}