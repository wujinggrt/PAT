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

vector<

// It 不过就是那些数据的索引，迭代器
// idea：也可以使用一个 vector 来存储吗，但是需要 # 来占用空结点
// 不适合
// 但是作为 其他遍历 的需求的话，把它放在 left 和 right 的递归的相应位置，
// 应该能够得到相应的结果。
template<typename It>
void decode_tree(It p_first, It p_last, It i_first, It i_last, Node& node) {
    auto root_val = *(p_last - 1);
    It root_inorder = i_first;
    // last表示左tree空
    // 从inorder中找到root所在位置，
    // 然后可以确定左边为left-tree, 右为right-tree.随后作为参数传入。
    while (*root_inorder != root_val) {
        ++root_inorder;
    }
    auto left_count = distance(i_first, root_inorder);
    // -1 为root。
    auto right_count = distance(i_first, i_last) - 1 - left_count;
    node.val = root_val;
    // left and right tree
    // 先还原左边的tree
    if (left_count > 0) {
        node.left = new Node;
        // postorder从最开始起，left_count即为left-tree
        // 在重新传入左子树的数据
        decode_tree(p_first, p_first + left_count, i_first, i_first + left_count, *(node.left));
    }
    if (right_count > 0) {
        node.right = new Node;
        // inorder的right-tree为root的右边
        // p_last is the next of root
        // 在重新传入右子树的数据
        decode_tree(p_first + left_count, p_last - 1, i_first + left_count + 1, i_last, *(node.right));
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