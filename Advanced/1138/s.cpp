#include <cstdio>
#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
using namespace std;

int main() {
    freopen("i.dat", "r", stdin);
    int n;
    cin >> n;
    vector<int> preorder(n);
    for (auto& node: preorder) {
        cin >> node;
    }
    vector<int> inorder{istream_iterator<int>(cin), istream_iterator<int>()};
    struct Node {
        int val;
        Node* left{nullptr};
        Node* right{nullptr};
    };
    function<void(Node*&, int, int, int, int)> build = 
        [&] (Node*& root, int pre_left, int pre_right, int in_left, int in_right) {
            if (pre_left > pre_right || in_left > in_right) {
                return ;
            }
            int val = preorder[pre_left];
            int root_pos_in = in_left;
            for (; inorder[root_pos_in] != val && root_pos_in <= in_right; ++root_pos_in) {
            }
            if (root == nullptr) {
                root = new Node{val};
            } else {
                root->val = val;
            }
            int num_left = root_pos_in - in_left;
            int num_right = in_right - root_pos_in;
            if (num_left > 0) {
                build(root->left, pre_left + 1, pre_left + num_left, in_left, in_left + num_left);
            }
            if (num_right > 0) {
                build(root->right, pre_left + num_left +1, pre_right, root_pos_in + 1, in_right);
            }
        };
    Node* tree{nullptr};
    build(tree, 0, preorder.size() - 1, 0, inorder.size() - 1);
    bool outputed = true;
    function<void(Node*)> posttraverse = [&] (Node* root) {
        if (root == nullptr) {
            return ;
        }
        posttraverse(root->left);
        posttraverse(root->right);
        if (outputed) {
            cout << root->val << endl;
            outputed = false;
        }
    };
    posttraverse(tree);
    //Node* left = tree->left;
    //to the most left
    //for (; left != nullptr && tree != nullptr; ) {
        //tree = left;
        //left = left->left;
    //}
     //到达了最左边，判断右子树，需要到达右子树最左边
    //for (left = tree->right; left != nullptr; ) {
        //tree = tree->left;
        //left = left->left;
    //}
    //if (tree->right != nullptr) {
        //cout << tree->right->val << endl;
    //} else {
        //cout << tree->val << endl;
    //}
}
