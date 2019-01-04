// 用hash提效率

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> score(n);
    for (int i = 0; i < n; ++i) {
        cin >> score[i];
    }
    int k;
    cin >> k;
    vector<int> order(k);
    unordered_map<int, int> m;
    for (int i = 0; i < k; ++i) {
        int temp;
        cin >> temp;
        // m.try_emplace(temp, 0);
        m[temp] = 0;
        order[i] = temp;
    }
    vector<int> count(k);
    for (const auto& e: score) {
        if (m.find(e) != m.end()) {
                ++m[e];
        }
    }
    cout << m[order[0]];
    for (int i = 1; i < order.size(); ++i) {
        cout << " " << m[order[i]];
    }
    return 0;
}