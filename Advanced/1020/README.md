根据后，中序遍历，还原binary_tree，然后level_order traverse.

使用queue来完成层序遍历。

根据postorder的最后一个元素找到root。然后这个root对应到inorder，确定inorder的root左侧为左子树，右侧为右子树。如此递归的查找下去，可以确定出原本的树。