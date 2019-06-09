#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
};

template<typename It>
void BuildTree(Node& node, It in_first, It in_last, It post_first, It post_last){
    auto val = *(post_last - 1);
    auto root_pos = in_first;
    for (; *root_pos != val; ++root_pos) {
    }
    int num_left = distance(in_first, root_pos);
    int num_right = distance(root_pos + 1, in_last);
    node.val = val;
    if (num_left > 0) {
        node.left = new Node;
        BuildTree(*node.left, in_first, root_pos, post_first, post_first + num_left);
    }
    if (num_right > 0) {
        node.right = new Node;
        BuildTree(*node.right, root_pos + 1, in_last, post_first + num_left, post_last - 1);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> inorder(n);
    for (auto& node: inorder) {
        cin >> node;
    }
    vector<int> postorder{istream_iterator<int>(cin), istream_iterator<int>()};
    Node root;
    BuildTree(root, begin(inorder), end(inorder), begin(postorder), end(postorder));
    vector<pair<Node*, int>> nodes;
    // second is the level
    // BFS
    deque<pair<Node*, int>> q;
    q.push_back({&root, 0});
    while (!q.empty()) {
        auto node = q.front();
        nodes.push_back(node);
        q.pop_front();
        if (node.first->left != nullptr) {
            q.push_back({node.first->left, node.second + 1});
        }
        if (node.first->right != nullptr) {
            q.push_back({node.first->right, node.second + 1});
        }
    }
    // 右到左打印，并且返回下一个左到右打印顺序的地方
    function<int(int)> zag_print = [&] (int i) -> int {
        if (i >= nodes.size()) {
            return nodes.size();
        } else if (nodes[i].second % 2 == 0) {
            int zag_end = zag_print(i + 1);
            cout << " ";
            cout << nodes[i].first->val;
            return zag_end;
        } else {
            return i;
        }
    };
    cout << nodes.front().first->val;
    for (int i = 1; i < nodes.size(); ) {
        if (nodes[i].second % 2 == 0) {
            i = zag_print(i);
        } else {
            cout << " ";
            cout << nodes[i].first->val;
            ++i;
        }
    }
    return 0;
}
