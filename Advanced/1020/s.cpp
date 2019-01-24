#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    uint32_t val;
    Node* left = nullptr;
    Node* right = nullptr;
};

vector<uint32_t> postorder;
vector<uint32_t> inorder;
Node tree;

template<typename It>
void decode_tree(It p_first, It p_last, It i_first, It i_last, Node& node) {
    auto root = *(p_last - 1);
    It i_left_tree = i_first;
    // last表示左tree空
    // 从inorder中找到root所在位置，
    // 然后可以确定左边为left-tree, 右为right-tree.随后作为参数传入。
    while (*i_left_tree != root) {
        ++i_left_tree;
    }
    auto left_cnt = distance(i_first, i_left_tree);
    // -1 为root。
    auto right_cnt = distance(i_first, i_last) - 1 - left_cnt;
    node.val = root;
    // left and right tree
    // 先还原左边的tree
    if (left_cnt > 0) {
        node.left = new Node;
        // postorder从最开始起，left_cnt即为left-tree
        decode_tree(p_first, p_first + left_cnt, i_first, i_first + left_cnt, *(node.left));
    }
    if (right_cnt > 0) {
        node.right = new Node;
        // inorder的right-tree为root的右边
        // p_last is the next of root
        decode_tree(p_first + left_cnt, p_last - 1, i_first + left_cnt + 1, i_last, *(node.right));
    }
}

void level_order() {
    vector<uint32_t> vec;
    queue<Node> q;
    q.push(tree);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        vec.push_back(node.val);
        if (node.left) {
            q.push(*node.left);
        }
        if (node.right) {
            q.push(*node.right);
        }
    }
    cout << vec.front();
    for (uint32_t i = 1; i < vec.size(); ++i) {
        cout << " " << vec[i];
    }
    cout << "\n";
}

int main() {
    uint32_t n;
    cin >> n;
    postorder = vector<uint32_t> (n, 0);
    inorder = vector<uint32_t> (n, 0);
    for (auto& e: postorder) {
        cin >> e;
    }
    for (auto& e: inorder) {
        cin >> e;
    }
    decode_tree(begin(postorder), end(postorder), begin(inorder), end(inorder), tree);
    level_order();
}