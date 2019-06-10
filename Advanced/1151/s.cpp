#include <cstdio>
#include <map>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main() {
  freopen("i.dat", "r", stdin);
  int m, n;
  cin >> m >> n;
  vector<int> inorder(n + 1);
  vector<int> preorder(n + 1);
  // 记录 root 在中序中的位置，方便以后索引
  map<int, int> position;
  for (int i = 1; i <= n; ++i) {
    cin >> inorder[i];
    position[inorder[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> preorder[i];
  }
  // pre_root is the left most position of preorder, is root yet.
  function<void(int, int, int, int, int)> lca =
    [&] (int in_left, int in_right, int pre_root, int a, int b) {
    if (in_left > in_right) {
      return;
    }
    int in_root = position[preorder[pre_root]];
    int a_inorder_position = position[a];
    int b_inorder_position = position[b];
    // a, b 在 root 的左侧，所以去左子树寻找. 
    if (a_inorder_position < in_root && b_inorder_position < in_root) {
      lca(in_left, in_root - 1, pre_root + 1, a, b);
    } else if ((a_inorder_position < in_root && b_inorder_position > in_root) ||
               (a_inorder_position > in_root && b_inorder_position < in_root)) {
      printf("LCA of %d and %d is %d.\n", a, b, inorder[in_root]);
    } else if (a_inorder_position > in_root && b_inorder_position > in_root) {
      // a, b 在 root 的右侧，需要去右侧寻找
      lca(in_root + 1, in_right, pre_root + 1 + (in_root - in_left), a, b);
    } else if (a_inorder_position == in_root) {
      printf("%d is an ancestor of %d.\n", a, b);
    } else if (b_inorder_position == in_root) {
      printf("%d is an ancestor of %d.\n", b, a);
    }
  };
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    // not exist
    if (position[a] == 0 && position[b] == 0) {
      printf("ERROR: %d and %d are not found.\n", a, b);
    } else if (position[a] == 0 || position[b] == 0) {
      printf("ERROR: %d is not found.\n", position[a] == 0 ? a : b);
    } else {
      lca(1, n, 1, a, b);
    }
  }
}
