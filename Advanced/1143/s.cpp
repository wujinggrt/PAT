#include <cstdio>
#include <iostream>
#include <functional>
using namespace std;

struct Node {
  int val;
  Node* left{nullptr};
  Node* right{nullptr};
};

void build(Node*& tree, int val) {
  if (tree == nullptr) {
    tree = new Node{val};
    return ;
  }
  if (val < tree->val) {
    build(tree->left, val);
  } else {
    build(tree->right, val);
  }
}

int main() {
  freopen("i.dat", "r", stdin);
  int m, n;
  cin >> m >> n;
  Node* tree{nullptr};
  for (; n-- > 0; ) {
    int val;
    cin >> val;
    build(tree, val);
  }
  bool is_lca = false;
  int lca_val = -1;
  bool is_ancestor = false;
  int ancestor_val = -1;
  // 1 contains former, (10)_base2 contains latter, (11)2 both
  function<int(Node*, int, int)> dfs = [&] (Node* root, int u, int v) {
    if (root == nullptr) {
      return 0;
    }
    int cur = 0;
    if (tree->val == u) {
      cur = 1 >> 0;
    } else if (tree->val == v) {
      cur = 1 >> 1;
    }
    auto left_node = dfs(root->left, u, v);
    auto right_node = dfs(root->right, u, v);
    auto lca = cur | left_node | right_node;
    if (lca == 3 && !is_lca) {
      cout << root->val << " lca" << endl;
      is_lca = true;
      lca_val = root->val;
    } else if (!is_ancestor) {
      cout << root->val << " ancestor" << endl;
      is_ancestor= true;
      ancestor_val = root->val;
    }
    return lca;
  };
  for (; m-- > 0; ) {
    is_lca = false;
    is_ancestor = false;
    int u, v;
    cin >> u >> v;
    int res = dfs(tree, u, v);
    if (res == 3) {
      cout << "LCA of " << u << " and " << v << " is " << lca_val << ".\n";
    } else if (res != 0) {
      printf("%d is an ancestor of %d.\n", ancestor_val, (res == 1 ? u : v));
    } else {
      printf("ERROR: 9 is not found.\n");
    }
  }
}
