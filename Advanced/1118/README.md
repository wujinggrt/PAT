# Birds in Forest

并查集:最需要注意的是一定要便利一遍**底层的结点而不是 parent 数组**，确定结点都绑定完 root，而不是中间层。

在使用一个 cnt 来保存 find_root 结果的 root 节点中的并查集的大小。获得鸟群数量。

并查集的套路：

第一次遍历 pic 是先存储，并且建立起 bird 到并查集的下标的 map。

第二次遍历 pic 开始 union。

接下来遍历并查集，is_root[root]++ 的操作使得一棵树有多少鸟的信息搞定。并且保存这个 root 到 set 中，方便下一次访问，

遍历 root，获得树的数量和鸟的数量。

bird_index 只有在遍历图片,或者用到鸟的 id 的时候用到，遍历 parent 的时候不会。

总结：

出错是因为：

1. 遍历了不是底层的 id，而是 parent，严重错误。
2. find_root 的 while (root != parent[root]) 中 parent[a] 写成这样啊了，错误的。