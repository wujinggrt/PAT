# Is It a Binary Search Tree

[reference](https://blog.csdn.net/IAccepted/article/details/20539395)

直接根据输入建树。 Why dose it make sense?

是因为我忽略了BST的事实？满二叉树？or完全二叉树？

想的太复杂了。

#### 分析

使用输入的一序列数字，直接插入到tree中去。建成一棵树后，然后在做判断。

        8
       /  \
      6    10
     / \   / \
    5   7 8  11

输入会不会出现如下复杂的情况。// 但是先序的结果都变了。

        8
       /  \
      6    11
     / \   /
    5   7 8
           \
            10

按照AC的代码，是不考虑下面的这种情况的。给的数字的顺序总是能够优先构建完全二叉树。

题目描述让人费解，回来审题：Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal sequence of a BST or the mirror image of a BST.

tell 这个序列是BST or mirror BST的reorder。

我们现在知道的条件为preorder，还有大小关系，那么我们自然有两个条件，可以还原二叉搜索树。

正如需要postorder和inorder这两个条件还原二叉树一样。

微妙的区别就是在于Binary Search Tree和Binary Tree。