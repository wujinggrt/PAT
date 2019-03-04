#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int32_t n;
    cin >> n;
    vector<int32_t> sequence_index(n);
    for (int32_t i = 0; i < n; ++i) {
        int32_t value;
        cin >> value;
        sequence_index[value] = i;
    }
    int32_t num_swaps = 0;
    for (int32_t i = 1; i < n; ++i) {
        // 在无序的情况下才swap，如果i在第i位上，这个i就有序了
        if (i != sequence_index[i]) {
            // swap(0, i),直到完成
            while (sequence_index[0] != 0) {
                swap(sequence_index[0], sequence_index[sequence_index[0]]);
                ++num_swaps;
            }
            if (i != sequence_index[i]) {
                swap(sequence_index[0], sequence_index[i]);
                ++num_swaps;
            }
        }
    }
    cout << num_swaps << "\n";
}