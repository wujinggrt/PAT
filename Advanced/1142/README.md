# Maximal Clique

every two distinct vertices in the clique are adjacent.

就是用矩阵来判断是否一个 vertex 是否包含其余的 vertex，使用 vector 来判断。

遍历第一次 queries，如果有内部两个不相邻，那么必不是 clique，输出。

反之，记录之前出现过的 query，可以使用 vector 或者 map，遍历那些没有出现过的 vertex，然后确定这些 vertex 是否与 queries 中的全都联系，得出结果。
