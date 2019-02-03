#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<int32_t> favorites;

vector<int32_t> stripe;

int32_t lcs() {
    // rows
    size_t row = favorites.size() - 1;
    // cols
    size_t col = stripe.size() - 1;
    vector<vector<int32_t>> table(row + 1, vector<int32_t>(col + 1, 0));
    for (size_t i = 1; i <= row; ++i) {
        for (size_t j = 1; j <= col; ++j) {
            auto max_entry = max({table[i - 1][j - 1], table[i - 1][j], table[i][j - 1]});
            if (favorites[i] == stripe[j]) {
                table[i][j] = max_entry + 1;
            } else {
                table[i][j] = max_entry;
            }
            cout << table[i][j] << " ";
        }
        cout << "\n";
    }
    return table[row][col];
}

int main() {
    int32_t n;
    cin >> n;
    int32_t m;
    cin >> m;
    favorites = vector<int32_t> (m + 1, 0);
    for (auto iter = begin(favorites) + 1; iter != end(favorites); ++iter) {
        cin >> *iter;
    }
    int32_t l;
    cin >> l;
    stripe = vector<int32_t> (l + 1, 0);
    for (auto iter = begin(stripe) + 1; iter != end(stripe); ++iter) {
        cin >> *iter;
    }
    cout << lcs() << "\n";
}