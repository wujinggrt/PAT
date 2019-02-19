# Complete Binary Search Tree

left subtree: < root, right subtree: >= root, both of them are bst.

首先，需要建树。

由于CBT，元素左靠。计算有多少层，然后由left subtree，right subtree个数计算出root的排名，结合offset得到在value_set的位子，建树。递归。

or 中序遍历，然后赋值，index++;