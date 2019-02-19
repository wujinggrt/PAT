#include <memory>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
    int32_t value;
    int32_t height;
    unique_ptr<Node> left = nullptr;
    unique_ptr<Node> right = nullptr;

    explicit Node(int32_t _value = 0) 
        : value(_value),
        height(0),
        left(nullptr),
        right(nullptr) {
    }
};

static const int32_t kAllowedImbalance = 1;

int32_t height(Node* node);
void rotate_left(unique_ptr<Node>& node);
void rotate_right(unique_ptr<Node>& n);
void double_rotate_left(unique_ptr<Node>& node);
void double_rotate_right(unique_ptr<Node>& node);
void insert(int32_t value, unique_ptr<Node>& node);
void balance(unique_ptr<Node>& node);
void level_order_traverse(Node* node);

int32_t height(Node* node) {
    return node == nullptr ? -1 : node->height;
}

void rotate_left(unique_ptr<Node>& node) {
    unique_ptr<Node> left_tmp = std::move(node->left);
    node->left = std::move(left_tmp->right);
    node->height = max(height(node->left.get()), height(node->right.get())) + 1;
    swap(left_tmp->right, node);
    swap(node, left_tmp);
    node->height = max(height(node->left.get()), height(node->right.get())) + 1;
}

void rotate_right(unique_ptr<Node>& node) {
    unique_ptr<Node> right_tmp = std::move(node->right);
    node->right = std::move(right_tmp->left);
    node->height = max(height(node->left.get()), height(node->right.get())) + 1;
    // 让node重新指向根
    swap(right_tmp->left, node);
    swap(node, right_tmp);
    node->height = max(height(node->left.get()), height(node->right.get())) + 1;
}

void double_rotate_left(unique_ptr<Node>& node) {
    rotate_right(node->left);
    rotate_left(node);
}

void double_rotate_right(unique_ptr<Node>& node) {
    rotate_left(node->right);
    rotate_right(node);
}

void insert(int32_t value, unique_ptr<Node>& node) {
    if (node == nullptr) {
        node = make_unique<Node>(value);
    } else if (value < node->value) {
        insert(value, node->left);
    } else if (value > node->value) {
        insert(value, node->right);
    }
    balance(node);
}

void balance(unique_ptr<Node>& node) {
    if (node == nullptr) {
        return ;
    }

    // 那一侧高了，就去哪一侧rotate
    // left-subtree is taller
    if (height(node->left.get()) - height(node->right.get()) > kAllowedImbalance) {
        if (height(node->left->left.get()) >= height(node->left->right.get())) {
            rotate_left(node);
        } else {
            double_rotate_left(node);
        }
    // right-subtree is taller
    } else if (height(node->right.get()) - height(node->left.get()) > kAllowedImbalance) {
        if (height(node->right->right.get()) >= height(node->right->left.get())) {
            rotate_right(node);
        } else {
            double_rotate_right(node);
        }
    }

    node->height = max(height(node->left.get()), height(node->right.get())) + 1;
}

void level_order_traverse(Node* node) {
    if (node == nullptr) {
        return ;
    }
    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
        auto node_ptr = q.front();
        q.pop();
        if (node_ptr->left != nullptr) {
            q.push(node_ptr->left.get());
        }
        if (node_ptr->right != nullptr) {
            q.push(node_ptr->right.get());
        }
    }
}

int main() {
    int32_t n;
    cin >> n;
    unique_ptr<Node> root = nullptr;
    for (int32_t i = 0; i < n; ++i) {
        int32_t node_value;
        cin >> node_value;
        insert(node_value, root);
    }
    cout << root->value;
}