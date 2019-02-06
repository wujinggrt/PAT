#include <unordered_map>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int32_t n;
    int32_t m;
    cin >> n >> m;
    vector<int32_t> coins(n);
    unordered_map<int32_t, int32_t> coin_map;
    coin_map.reserve(n);
    for (auto& coin: coins) {
        cin >> coin;
        coin_map[coin]++;
    }
    sort(begin(coins), end(coins));
    for (auto face: coins) {
        auto iter = coin_map.find(m - face);
        if (iter == end(coin_map)) {
            continue;
        }
        if (((face == m - face) && iter->second >= 2) || 
            (face != m - face)) {
            cout << face << " " << m - face << "\n";
            return 0;
        }
    }
    cout << "No Solution\n";
}