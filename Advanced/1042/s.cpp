#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    int32_t k;
    cin >> k;
    vector<int32_t> order(54);
    for (auto& e: order) {
        cin >> e;
        --e;
    }
    vector<string> cards;
    cards.reserve(54);
    for (int32_t j = 0; j < 4; ++j) {
        string tmp{"SHCD"};
        for (int32_t i = 1; i <= 13; ++i) {
            cards.push_back(tmp[j] + to_string(i));
        }
    }
    cards.push_back("J1"s);
    cards.push_back("J2"s);
    // 映射到cards的map
    unordered_map<int32_t, int32_t> m;
    m.reserve(54);
    for (int32_t i = 0; i < 54; ++i) {
        m[i] = i;
    }
    for (int32_t i = 0; i < k; ++i) {
        unordered_map<int32_t, int32_t> tmp;
        tmp.reserve(54);
        for (size_t j = 0; j < 54; ++j) {
            tmp[order[j]] = m[j];
        }
        m = tmp;
    }
    bool first = true;
    for (size_t i = 0; i < 54; ++i) {
        if (first) {
            first = false;
        } else {
            cout << " ";
        }
        cout << cards[m[i]];
    }
}