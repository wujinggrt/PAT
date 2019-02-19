#include <cstdio>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int32_t n;
    cin >> n;
    vector<unordered_set<int32_t>> input_sets(n);
    for (auto& numbers: input_sets) {
        int32_t num;
        scanf("%d", &num);
        numbers.reserve(num);
        for (int32_t i = 0; i < num; ++i) {
            int32_t integer;
            scanf("%d", &integer);
            numbers.insert(integer);
        }
    }
    int32_t k;
    cin >> k;
    for (size_t i = 0; i < k; ++i) {
        int32_t former;
        int32_t latter;
        scanf("%d %d", &former, &latter);
        int32_t num_common = 0;
        for (const auto& num: input_sets[latter - 1]) {
            auto iter = input_sets[former - 1].find(num);
            if (iter != end(input_sets[former - 1])) {
                ++num_common;
                continue;
            }
        }
        double total_distinct = static_cast<double>(input_sets[former - 1].size() + input_sets[latter - 1].size() - num_common);
        printf("%.1f%%\n", (static_cast<double>(num_common) / total_distinct) * 100);
    }
}