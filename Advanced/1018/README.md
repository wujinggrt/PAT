抽象问题，最短路径=>Dijkstra。但是问题在于，怎么解决相同长度的路径的问题？查看这个station是否更接近5？half_full。

If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.

Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. 

以上两个信息，决定筛选出重复的路径。

bike - cmax / 2, 正数则送到下一层，负的则从上一层接收。

#### DFS 穷举

使用dfs，找出所有最短路径和最优解。[site](https://blog.csdn.net/tjj1998/article/details/79731632)

首先一直dfs，直到遍历到sp，也就是目标点。然后开始比较distance和bring，take。

注意回溯的情况，如果dfs到了sp，也就是目的地，那么开始回溯，重置之前的status。又开始下一条路。

#### Dijkstra + Dfs

只有在所有路径都确定了之后才能区选择最小的need和最小的back～, dijkstra + dfs. [site](https://www.liuchuo.net/archives/2373)

在最短路径确定的时候，使用vector保存具有相同distance的parent。然后从sp开始dfs，通过这些单一的或者多个的parent来决定。

问题在于，这样的保存能够存储到所有的最短路径情况吗？

与这个点相连接的，都可能存在相等长度的情况，那么目标点v和源点u, pre[v] 就是一个值的集合。

pre[v]的作用：对于找到的最短的dis[u]，两种情况：  
1. dis[v] > dis[u] + edge[u][v], 那么u到v的距离加上dis[u]最短，那么就pre[v]更新，只包含u.
2. dis[v] == dis[u] + edge[u][v]，那么就存在另外一条到v这个目标点（dst）的**最短路径**，存到pre[v]中。

由于每次总会遍历，所以所以情况都会考虑进来，那么所以最短路径都被包含到上述两种情况。其中，情况2最可能出现在找到当前最短dis的时候，也就是优先队列的Extract的时候出现相同的长度。

dfs函数实际只是对多条路径的深度搜索。

在dfs中，先保存遍历过的station，直到遍历到起始点0（PBMC)。然后在开始处理数据，从PBMC这个点来出发，处理send和take_back等数量。

这个方法保存相等长度的路径。然后在回遍历所有的最短路径。