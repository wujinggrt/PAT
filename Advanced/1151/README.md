# LCA in a Binary Tree

首先判断 a, b 是否存在，通过 map 就可以。

a, b 是否在当前 root 两侧，是的话就可以输出，否则 a, b 在 root 的左子树或者右子树，那么就递归的下去寻找。

不需要构建树，只需要和构建树的时候一样递归就可以了，需要的是确定 root 的位置，两个 traverse track 能够做到。
