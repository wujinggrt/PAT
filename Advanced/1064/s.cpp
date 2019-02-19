#include <cmath>
#include <queue>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

struct Node {
    int32_t value;
    shared_ptr<Node> left = nullptr;
    shared_ptr<Node> right = nullptr;

    explicit Node(int32_t _value = -1) : value(_value) {}
};

int main() {
    int32_t n;
    auto tree = make_shared<Node>();
    cin >> n;
    vector<int32_t> value_sets(n);
    for (auto& value: value_sets) {
        scanf("%d", &value);
    }
    sort(begin(value_sets), end(value_sets));
    function<void(Node*, int32_t, int32_t)> build_tree = [&] (Node* root, int32_t num_nodes, int32_t offset) {
        if (offset >= n) {
            return;
        }
        if (num_nodes == 1) {
            root->value = value_sets[offset];
            return;
        }
        // 换底公式，计算多少层 log2（(2^n - 1) + 1）向上取整,需要计算出有n层
        double num_levels_tmp = log(num_nodes + 1) / log(2.);
        int32_t num_levels = static_cast<int32_t>(num_levels_tmp);
        // 向上取整
        if (static_cast<double>(num_levels) < num_levels_tmp) {
            ++num_levels;
        }
        // 计算有左右子树，然后根据个数和offset来判断root的位子，最后递归下去
        int32_t num_left_nodes = 0;
        int32_t num_right_nodes = 0;
        int32_t num_without_last_level = static_cast<int32_t>(pow(2, num_levels - 1)) - 1;
        // 第二层直到倒数第二层的个数 / 2
        // - 1 是减去root
        num_left_nodes = num_right_nodes = (num_without_last_level - 1) / 2;
        int32_t num_last_level_nodes = static_cast<int32_t>(pow(2, num_levels - 1));
        // right subtree has nodes
        if (num_nodes - num_without_last_level > num_last_level_nodes / 2) {
            num_left_nodes += num_last_level_nodes / 2;
            num_right_nodes += num_nodes - num_without_last_level - num_last_level_nodes / 2;
        } else {
            num_left_nodes += num_nodes - num_without_last_level;
        }
        root->value = value_sets[offset + num_left_nodes];
        // cout << num_levels << " " << num_nodes << " " << num_without_last_level << " " << num_last_level_nodes << " " << offset << " " << num_left_nodes << " " << num_right_nodes << "\n";
        if (num_left_nodes != 0) {
            root->left = make_shared<Node>();
            build_tree(root->left.get(), num_left_nodes, offset);
        }
        if (num_right_nodes != 0) {
            root->right = make_shared<Node>();
            build_tree(root->right.get(), num_right_nodes, offset + num_left_nodes + 1);
        }
    };
    build_tree(tree.get(), n, 0);
    queue<shared_ptr<Node>> buffer;
    buffer.push(tree);
    bool first = true;
    while (!buffer.empty()) {
        auto node = buffer.front();
        if (first) {
            first = false;
        } else {
            cout << " ";
        }
        cout << node->value;
        buffer.pop();
        if (node->left != nullptr) {
            buffer.push(node->left);
        }
        if (node->right != nullptr) {
            buffer.push(node->right);
        }
    }
}