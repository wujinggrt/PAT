#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <functional>
#include <vector>
#include <iterator>
using namespace std;

struct Entry {
    int id;
    int num;
};

int main() {
    int n, k;
    cin >> n >> k;
    auto cmp = [] (const Entry& lhs, const Entry& rhs) {
        return lhs.num != rhs.num ? lhs.num > rhs.num : lhs.id < rhs.id; 
    };
    set<Entry, decltype(cmp)> s(cmp);
    map<int, int> occured;
    for (int i = 0; i < n; ++i) {
        int item;
        cin >> item;
        if (i == 0) {
            s.insert({item, 1});
            occured.insert({item, 1});
            continue;
        }
        printf("%d:", item);
        int j = 0;
        for (auto& entry: s) {
            j < k ? ++j : ({break; 0;});
            printf(" %d", entry.id);
        }
        cout << "\n";
        auto p = occured.insert({item, 1});
        if (!p.second) {
            //++p.first->second;
            //auto p = s.find(
            auto entry = p.first;
            s.erase({entry->first, entry->second});
            ++entry->second;
            s.insert({entry->first, entry->second});
        } else {
            s.insert({item, 1});
        }
    }
    return 0;
}
