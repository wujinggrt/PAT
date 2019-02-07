# Path of Equal Weight

使用vector来存储孩子node。

建立起tree.

在建立的时候，通过ID来查找对应的node。那么就需要去随机搜索。那么就不用unique_ptr，用shared_ptr，并且需要借助map or vector。

cmp默认返回值为true则会segment fault。因为空的vec到前面去了。

然后使用dfs，剪枝+回溯。注意，需要traverse到leaf，并且weight == s，否则不满足要求。