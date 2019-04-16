#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    int course[1000] = {0};
    cin >> n;
    // init set
    vector<int> parent(n);
    iota(begin(parent), end(parent), 0);
    vector<unordered_set<int>> socials(n);
    function<int(int)> find_root = [&] (int i) {
        int root = i;
        while (root != parent[root]) {
            root = parent[root];
        }
        // update
        while (root != parent[i]) {
            int cur = parent[i];
            parent[i] = root;
            i = cur;
        }
        return root;
    };
    function<void(int, int)> union_set = [&] (int a, int b) {
        a = find_root(a);
        b = find_root(b);
        if(a != b) {
            parent[b] = a;
        }
    };
    for (auto& people: socials) {
        int k;
        scanf("%d:", &k);
        for (int i = 0; i < k; ++i) {
            int h;
            cin >> h;
            people.insert(h);
        }
    }
    for (int i = 0; i < n; ++i) {
        int a = find_root(i);
        for (int j = i + 1; j < n; ++j) {
            // 可能没有考虑到他们自己的 set
            int b = find_root(j);
            if (a != b) {
                for (auto e: socials[a]) {
                    auto iter = socials[b].find(e);
                    if (iter != end(socials[b])) {
                        union_set(a, b);
                        socials[a].insert(begin(socials[b]), end(socials[b]));
                        break;
                    }
                }
            }
        }
    }
    // 这个不行，因为有些还没有更新 root， 指向的 root 还没有指向他自己
    // unordered_map<int, int> clusters;
    // for (auto i: parent) {
    //     ++(clusters[i]);
    // }
    // cout << clusters.size() << "\n";
    // bool f = true;
    // vector<int> nums;
    // for (auto& entry: clusters) {
    //     nums.push_back(entry.second);
    // }
    // sort(begin(nums), end(nums), std::greater<int>());
    // for (auto num: nums) {
    //     if (f) {
    //         f = false;
    //     } else {
    //         cout << " ";
    //     }
    //     cout << num;
    // }

    vector<int> is_root(n, 0);
    for (int i = 0; i < n; ++i) {
        is_root[find_root(i)]++;
    }
    int cnt = 0;
    for (auto num: is_root) {
        if (num != 0) {
            ++cnt;
        }
    }
    sort(begin(is_root), end(is_root), greater<int>());
    cout << cnt << "\n";
    for (int i = 0; i < cnt; ++i) {
        if (i != 0) {
            cout << " ";
        }
        cout << is_root[i];
    }
}