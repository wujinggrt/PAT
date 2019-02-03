#include <functional>
#include <vector>
#include <memory>
#include <iostream>
using namespace std;

struct Node {
    int32_t val;
    unique_ptr<Node> left = nullptr;
    unique_ptr<Node> right = nullptr;

    Node() = default;
    Node(int32_t v) 
        : val{v},
        left{nullptr},
        right{nullptr} {}
};

unique_ptr<Node> tree = nullptr;
vector<int32_t> nodes;
vector<int32_t> pretrack;
vector<int32_t> posttrack;
vector<int32_t> mirrortrack;

void insert(Node* root, int32_t val) {
    if (!root) {
        return ;
    }
    if (val < root->val) {
        if(root->left) {
            insert(root->left.get(), val);
        } else {
            root->left = make_unique<Node>(val);
        }
    } else {
        if(root->right) {
            insert(root->right.get(), val);
        } else {
            root->right = make_unique<Node>(val);
        }
    }
}

void preorder(Node* root) {
    if (root == nullptr) {
        return ;
    }
    pretrack.push_back(root->val);
    preorder(root->left.get());
    preorder(root->right.get());
}

void postorder(Node* root) {
    if (!root) {
        return ;
    }
    postorder(root->left.get());
    postorder(root->right.get());
    posttrack.push_back(root->val);
}

void mirror(Node* root) {
    if (!root) {
        return ;
    }
    mirrortrack.push_back(root->val);
    mirror(root->right.get());
    mirror(root->left.get());
}

void swap_subtree(Node* root) {
    if (!root) {
        return ;
    }
    swap(root->left, root->right);
    swap_subtree(root->left.get());
    swap_subtree(root->right.get());
}

int main() {
    int32_t n;
    cin >> n;
    nodes = vector<int32_t> (n);
    pretrack.reserve(n);
    posttrack.reserve(n);
    for (auto& e: nodes) {
        cin >> e;
        if (tree) {
            insert(tree.get(), e);
        } else {
            tree = make_unique<Node>(e);
        }
    }
    preorder(tree.get());
    mirror(tree.get());
    auto printer = [&] () {
        cout << "YES\n";
        postorder(tree.get());
        bool first = true;
        for (const auto& e: posttrack) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << e;
        }
        cout << "\n";
    };
    if (pretrack == nodes) {
        printer();
    } else if (mirrortrack == nodes) {
        swap_subtree(tree.get());
        printer();
    } else {
        cout << "NO\n";
    }
}