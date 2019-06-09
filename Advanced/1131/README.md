# Subway Map

假设前一个站是pre，当前站是curr，下一个站是next，若mp[pre][curr]≠mp[curr][next]，说明需要一次换乘，顺序遍历路径path的所有站点，即可求出换乘次

复杂点在于 线 的添加，使得不再是简单的 dfs 和 Dijkstra, 本题的思路关键点在于 线 和 站点 的解耦。

1. 使用 next_station 记录两个相邻站点，通过其中一个就可以找到这个站点通向附近的那个站点。(unordered_map<int, vector<int>>)
2. 使用 line_id[from][dst] 来获取两站之间的 线号。( unordered_map<int, unordered_map<int, int>>)
3. 输出：在出现换乘的时候在输出上一条线的其实和终点站。
