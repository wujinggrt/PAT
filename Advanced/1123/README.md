# Is It a Complete AVL Tree

one by one into an initially empty AVL tree.

是否 complete, 那就使用 index or array 来辅助完成，如果出现跳了，那就说明最后一个 last_index_of_node > n;

左孩子就 += 2.


居然忘记了在 Balance 最后更新高度。总之所有可能改变的地方更改高度。