#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int32_t n;
    cin >> n;
    vector<int32_t> bets(n);
    unordered_map<int32_t, bool> records;
    records.reserve(n);
    for (auto& e: bets) {
        cin >> e;
        auto iter = records.find(e);
        if (iter == end(records)) {
            records.insert({e, true});
        } else {
            iter->second = false;
        }
    }
    for (auto& e: bets) {
        if (records[e]) {
            cout << e;
            return 0;
        }
    }
    cout << "None";
}