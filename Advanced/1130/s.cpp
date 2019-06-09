#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <iterator>
#include <vector>
using namespace std;

struct Node {
    string data;
    int l, r;
    int p{-1}; // record parent
};

int main() {
    int n;
    cin >> n;
    vector<Node> tree(n);
    for (int i = 0; i < n; ++i) {
        auto& node = tree[i];
        cin >> node.data >> node.l >> node.r;
        if (node.l != -1) {
            --node.l;
            tree[node.l].p = i;
        }
        if (node.r != -1) {
            --node.r;
            tree[node.r].p = i;
        }
    }
    auto root = distance(begin(tree), find_if(begin(tree), end(tree), [] (const Node& node) { return node.p == -1; }));
    function<void(int, bool)> inorder = [&] (int i, bool is_root) {
        if (tree[i].l == -1) {
            if (tree[i].r == -1) {
                cout << tree[i].data;
            } else {
                cout << (is_root ? "" : "(") << tree[i].data;
                inorder(tree[i].r, false);
                cout << (is_root ? "" : ")");
            }
        } else if (tree[i].r != -1) {
            cout << (is_root ? "" : "(");
            inorder(tree[i].l, false);
            cout << tree[i].data;
            inorder(tree[i].r, false);
            cout << (is_root ? "" : ")");
        }
    };
    inorder(root, true);
}
