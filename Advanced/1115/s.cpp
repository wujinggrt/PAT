#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* l = nullptr;
    Node* r = nullptr;

    Node(int _val) : val(_val) {}
};

int max_deep = 1;
int temp_deep = 1;

void Insert(Node* root, int n) {
    ++temp_deep;
    if (n <= root->val) {
        if (root->l == nullptr) {
            root->l = new Node(n);
            if (max_deep < temp_deep) {
                max_deep = temp_deep;
            }
            temp_deep = 1;
        } else {
            Insert(root->l, n);
        }
    } else {
        if (root->r == nullptr) {
            root->r = new Node(n);
            max_deep = max(max_deep, temp_deep);
            temp_deep = 1;
        } else {
            Insert(root->r, n);;
        }
    }
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;
    vector<int> nums(n);
    for (auto& num: nums) {
        cin >> num;
        if (root == nullptr) {
            root = new Node(num);
        } else {
            Insert(root, num);
        }
    }
    int num_lowest = 0;
    int num_lowest_above = 0;
    queue<pair<Node*, int>> q;
    q.push({root, 1});
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (node.second == max_deep) {
            ++num_lowest;
        } else if (node.second == max_deep - 1) {
            ++num_lowest_above;
        }
        if (node.first->l != nullptr) {
            q.push({node.first->l, node.second + 1});
        }
        if (node.first->r != nullptr) {
            q.push({node.first->r, node.second + 1});
        }
    }
    printf("%d + %d = %d\n", num_lowest, num_lowest_above, num_lowest + num_lowest_above);
}