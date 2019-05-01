#include <set>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    // 从 set 中，由其中一人在 unordered_map 到对象
    unordered_map<string, string> couple;
    for (int i = 0; i < n; ++i) {
        string f, m;
        cin >> f >> m;
        couple.insert({f, m});
        couple.insert({m, f});
    }
    int m;
    cin >> m;
    unordered_set<string> party{istream_iterator<string>(cin), istream_iterator<string>()};
    set<string> ans;
    for (auto iter = begin(party); iter != end(party); ++iter) {
        auto iter_couple = couple.find(*iter);
        // 单身或者伴侣不在
        if (iter_couple == end(couple) ||
            party.find(iter_couple->second) == end(party)) {
            ans.insert(*iter);
        }
    }
    cout << ans.size() << "\n";
    bool first = true;
    for (auto& s: ans) {
        if (first) {
            first = false;
        } else {
            cout << " ";
        }
        cout << s;
    }
}