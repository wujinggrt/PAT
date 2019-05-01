#include <numeric>
#include <iterator>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> pic(n);
    // 用作下标，给 parent 当参考数量
    int total_birds = 0;
    unordered_map<int, int> bird_index;
    for (auto& row: pic) {
        int k;
        cin >> k;
        row = vector<int>(k);
        for (auto& bird: row) {
            cin >> bird;
            // 插入成功，说明这只鸟出现过
            if (bird_index.insert({bird, total_birds}).second) {
                ++total_birds;
            }
        }
    }
    vector<int> parent(total_birds);
    iota(begin(parent), end(parent), 0);
    function<int(int)> find_root = [&] (int a) {
        int root = a;
        while (root != parent[root]) {
            root = parent[root];
        }
        while (a != parent[a]) {
            int cur = a;
            a = parent[a];
            parent[cur] = root;
        }
        return root;
    };
    function<void(int, int)> union_set = [&] (int a, int b) {
        int root_a = find_root(a);
        int root_b = find_root(b);
        if (root_a != root_b) {
            parent[root_b] = root_a;
        }
    };
    for (auto& row: pic) {
        int id = row.front();
        for (int i = 1; i < row.size(); ++i) {
            union_set(bird_index[id], bird_index[row[i]]);
        }
    }
    vector<int> is_root(parent.size(), 0);
    unordered_set<int> tree_count;
    // 并没有更新
    for (int i = 0; i < parent.size(); ++i) {
        int root = find_root(i);
        is_root[root]++;
        tree_count.insert(root);
    }
    int num_birds = accumulate(begin(tree_count), end(tree_count), 0, [&] (auto res, auto r) {
        return res + is_root[r];
    });
    cout << tree_count.size() << " " << num_birds << "\n";
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        int root_a = find_root(bird_index[a]);
        int root_b = find_root(bird_index[b]);
        cout << (root_a == root_b ? "Yes\n" : "No\n");
    }
}