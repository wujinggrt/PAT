#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
    int id;
    int parent;
    int level = 0;
    vector<int> children;
};

int main() {
    int n, m;
    cin >> n >> m;
    // 不添加这个 case, 那么就会 fail 测试点
    // 数据结构的 family 的层数肯定没有，自然 iter 等运算会有问题。
    if (n != 0 && m == 0) { 
        cout << "1 1\n";
        return0；
    }
    vector<Node> family(n);
    // root
    family[0].parent = 0;
    // 01 是 root, 使用 id - 1 来 index.
    for (int i = 0; i < m; ++i) {
        int id, k;
        cin >> id >> k;
        --id;
        family[id].children.reserve(k);
        for (int j = 0; j < k; ++j) {
            int child;
            cin >> child;
            --child;
            family[id].children.push_back(child);
            family[child].parent = id;
        }
    }
    vector<int> num_level(family.size(), 0);
    function<void()> level_traverse = [&] () {
        int start = 0;
        family[start].level = 1;
        queue<int> generation;
        generation.push(start);
        while (!generation.empty()) {
            int parent = generation.front();
            generation.pop();
            int cur_level = family[parent].level;
            ++(num_level[cur_level]);
            for (auto child: family[parent].children) {
                generation.push(child);
                family[child].level = cur_level + 1;
            }
        }
    };
    level_traverse();
    // n 个孤立的结点
    auto iter = max_element(begin(num_level), end(num_level));
    cout << *iter << " " << distance(begin(num_level), iter) << "\n";
}