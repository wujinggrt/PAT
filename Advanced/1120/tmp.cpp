#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>
#include <map>
using namespace std;

int main() {
    vector<int> vec{1, 2, 3, 4,  5};
    set<int> st;
    copy(begin(vec), end(vec), inserter(st, begin(st)));
    for (auto n: st) {
        cout << n << " ";
    }
    cout << "\n";
    vector<pair<int, int>> vecp{{1, 2}, {3, 4}};
    map<int, int> mp;
    copy_if(begin(vecp), end(vecp), inserter(mp, begin(mp)), [] (pair<int, int> p) {
        return p.first == 1;
    });
    for (auto entry: mp) {
        cout << entry.first << " " << entry.second << "\n";
    }
}