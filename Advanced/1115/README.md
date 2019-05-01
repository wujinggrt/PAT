# Counting Nodes in a BST

left subtree: less than or equal to the node's key.

层序遍历。

为什么会有 0 个元素在其中一层？

测试点 5：当只有一个元素的时候，需要显示 1 + 0 = 0，也就是需要 max_deep 初始化为 1.