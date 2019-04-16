#include <functional>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<string, unordered_set<string>> incompatible;
    for (int i = 0; i < n; ++i) {
        string former;
        string latter;
        cin >> former >> latter;
        incompatible[former].insert(latter);
        incompatible[latter].insert(former);
    }#
    for (int i = 0; i < m; ++i) {
        int num;
        cin >> num;
        vector<string> goods(num);
        for (auto& s: goods) {
            cin >> s;
        }
        bool ok_together = true;
        for (int i = 0; i < goods.size() && ok_together; ++i) {
            for (int j = i + 1; j < goods.size(); ++j) {
                auto iter = incompatible.find(goods[i]);
                if (iter == end(incompatible)) {
                    break;
                } else {
                    auto iter_latter = iter->second.find(goods[j]);
                    if (iter_latter != iter->second.end()) {
                        ok_together = false;
                        break;
                    }
                }
            }
        }
        if (ok_together) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

/*
不好的思路


struct Node {
    string id;
    int parent = -1;
};


void f() {
        unordered_map<string, int> indices;
    vector<Node> goods;
    function<int(int)> find_root = [&] (int i) {
        auto root = i;
        while (root != goods[root].parent) {
            root = goods[root].parent;
        }
        while (i != goods[i].parent) {
            int cur = i;
            i = goods[i].parent;
            goods[cur].parent = root;
        }
        return root;
    };
    function<void(int, int)> union_set = [&] (int a, int b) {
        auto ra = find_root(a);
        auto rb = find_root(b);
        if (ra != rb) {
            goods[rb].parent = ra;
        }
    };
    for (int i = 0; i < n; ++i) {
        string former, latter;
        cin >> former >> latter;
        auto iter_f = indices.find(former);
        auto iter_l = indices.find(former);
        if (iter_f == end(indices)) {
            indices[former] = goods.size();
            goods.push_back({former, static_cast<int>(goods.size())});
        }
        if (iter_l == end(indices)) {
            indices[latter] = goods.size();
            goods.push_back({latter, static_cast<int>(goods.size())});
        }
        auto former_index = indices[former];
        auto latter_index = indices[latter];
        union_set(former_index, latter_index);
    }
    for (int i = 0; i < m; ++i) {
        int num;
        cin >> num;
        unordered_set<int> roots;
        bool incompatible = false;
        for (int j = 0; j < num; ++j) {
            string id;
            cin >> id;
            auto iter = indices.find(id);
            if (iter != end(indices)) {
                auto index = indices[id];
                auto cur_root = find_root(index);
                auto iter_s = roots.find(cur_root);
                if (iter_s != end(roots)) {
                    printf("Nooo, id:%s index:%d cur_root:%d\n", id.c_str(), index, cur_root);
                    incompatible = true;
                    break;
                } else {
                    roots.insert(cur_root);
                }
            }
        }
        if (incompatible) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
}
*/