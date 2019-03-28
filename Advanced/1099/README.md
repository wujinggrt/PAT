# Build A Binary Search Tree

从题意，是排序。左边有 num_lsubtree 个，那么 root 就是第 num_lsubtree 名。

首先根据顺序建树。

给出的顺序是中序遍历的顺序，总是给出 root 然后再给出 left，然后从 left 访问，给出左右结点的序号，或者是 -1。 表示没有。直到终点。在访问 right。

利用这个特性，就可以在中序遍历的时候进行赋值。