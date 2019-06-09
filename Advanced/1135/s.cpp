#include <iostream>
#include <cstdio>
#include <vector>
#include <memory>
#include <functional>
using namespace std;

struct Node {
    int val;
    Node* left{nullptr};
    Node* right{nullptr};
};

void build(Node*& root, int val) {
    if (root == nullptr) {
        root = new Node{val};
        return;
    }
    if (abs(val) < abs(root->val)) {
        build(root->left, val);
    } else {
        build(root->right, val);
    }
}

bool red_connected(Node* root) {
    if (root == nullptr) {
        return false;
    }
    bool cur_red_connected = false;
    if (root->val < 0) {
        if (root->left != nullptr && root->left->val < 0) {
            cur_red_connected = true;
        }
        if (root->right != nullptr && root->right->val < 0) {
            cur_red_connected = true;
        }
    }
    bool connected_with_left = red_connected(root->left);
    bool connected_with_right = red_connected(root->right);
    return cur_red_connected || connected_with_left || connected_with_right;
}

bool is_rbtree = true;

int dfs(Node* tree) {
    // leaf is black
    if (tree == nullptr) {
        return 1;
    }
    auto left_height = dfs(tree->left);
    auto right_height = dfs(tree->right);
    if (left_height != right_height) {
        is_rbtree = false;
    }
    return left_height + (tree->val < 0 ? 0 : 1);
}

int main(){
    freopen("i.dat", "r", stdin);
    int k;
    cin >> k;
    for (; k-- != 0; ) {
        int n;
        cin >> n;
        vector<int> preorder(n);
        Node* tree{nullptr};
        for (auto& node: preorder) {
            cin >> node;
            build(tree, node);
        }
        if(preorder.front() < 0) {
            cout << "No\n";
            continue;
        }
        is_rbtree = true;
        dfs(tree);
        cout << (!red_connected(tree) && is_rbtree ? "Yes\n" : "No\n");
    }
}
