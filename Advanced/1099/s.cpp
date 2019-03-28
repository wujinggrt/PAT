#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <functional>
using namespace std;

struct Node {
    int val;
    int left;
    int right;
};

int main() {
    int n;
    cin >> n;
    vector<Node> tree(n);
    vector<int> val(n);
    for (auto& node: tree) {
        cin >> node.left >> node.right;
    }
    for (auto& num: val) {
        cin >> num;
    }
    sort(begin(val), end(val));
    int index = 0;
    function<void(Node&)> inorder = [&] (Node& root) {
        if (root.left != -1) {
            inorder(tree[root.left]);
        }
        root.val = val[index];
        ++index;
        if (root.right != -1) {
            inorder(tree[root.right]);
        }
    };
    inorder(tree.front()); // root 为 0
    function<void(Node)> level = [&] (Node root) {
        queue<Node> q;
        q.push(root);
        bool first = true;
        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << tmp.val;
            if (tmp.left != -1) {
                q.push(tree[tmp.left]);
            }
            if (tmp.right != -1) {
                q.push(tree[tmp.right]);
            }
        }
    };
    level(tree.front());
    cout << "\n";
}