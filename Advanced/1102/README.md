# Invert a Binary Tree

只要找到了思路，还是比较简单的。

反向输出，right-tree root left-tree。

首先存储 node 在每一个 vector 中。然后记录它的 parent。一开始初始化 node 的时候， parent 设置为 -1。没找到一个左右孩子，就把他的 parent 设置为当前的结点。然后到最后，找到 parent 为 -1 的结点，这个结点也就是 root。根据 right/left 索引计科进行对树的操作。