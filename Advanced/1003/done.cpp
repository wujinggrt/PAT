// #include <iostream>
// #include <cmath>
// #include <stdio.h>
// #include <climits>
// #include <string.h>

// using namespace std;

// static const int N = 501;

// static int city[N];
// static int matrix[N][N];
// static bool visit[N];

// static int n, m, from, to, c1, c2, length;
// static int path_count = 0, man_count = 0;
// static long long min_length = LLONG_MAX;

// //length:到当前城市(编号cid)的距
// //mans:从起始城市走到当前城市，所累积的gather到的team数 
// //cid:当前城市编号
// void dfs(int length, int total_mans, int cid)
// {
//     //找到目的地要更新 计数
//     if (cid == to)
//     {
//         if (length > min_length) 
//         {
//             return;
//         }
//         // 最小路径只有当前这一条
//         else if (length < min_length)
//         {
//             path_count = 1;
//             min_length = length;
//             man_count = total_mans;
//         }
//         else
//         {
//             ++path_count;
//             if (man_count < total_mans)
//             {
//                 man_count = total_mans;
//             }
//         }
//         return;
//     }

//     //剪枝，如果距离大于最小距离，这条路将不用继续走下去了
//     if (length > min_length)
//     {
//         return;
//     }
//     // 能够确保所有的路线都考虑到，走完（当然，一旦发现length太大就return）
//     for (int i = 0; i < n; ++i)
//     {
//         // 不通 or 访问过了
//         if (matrix[cid][i] == -1 || visit[i])
//         {
//             continue;
//         }
//         visit[i] = true;
        
//         // 回溯
//         dfs(length + matrix[cid][i], total_mans + city[i], i);
//         // 已经从这个点回来了，访问完了，可以“解锁”，下次能在继续访问
//         visit[i] = false;
//     }
// }

// int main()
// {
//     //-1表示i和j表示的城市之间无通路
//     memset(matrix, -1, sizeof(matrix));
//     memset(visit, 0, sizeof(visit));
//     cin >> n >> m >> from >> to;
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> city[i];
//     }
//     for (int i = 0; i < m; ++i)
//     {
//         cin >> c1 >> c2 >> length;
//         matrix[c1][c2] = matrix[c2][c1] = length;
//     }

//     visit[from] = true;
//     dfs(0, city[from], from);
//     visit[from] = false;

//     cout << path_count << " " << man_count << endl;
//     return 0;
// }

// #include<stdio.h>
// int mp[505][505]; //模拟地图
// int book[505]; //标记数组
// int dis[505]; //记录边的数组
// int count[505];  //路的数目
// int w[505];    //救援队，权值
// int city[505];  //初始化的救援队
// int n,m,c1,c2;
// int inf = 0X3f3f3f3f;
// void init()
// {
//     for(int i = 0;i < n;i++){
//         for(int j = 0;j < n;j++){
//             if(i == j){
//                 mp[i][j] = 0;
//             }
//             else{
//                 mp[i][j] = inf;
//             }
//         }
//     }
//     for(int i = 0;i < n;i++){
//         book[i] = 0;
//         count[i] = 0;
//         w[0] = 0;
//     }
// }
// void dij()
// {
 
//     count[c1] = 1;
//     w[c1] = city[c1];
//     book[c1] = 1;
//     for(int i = 0;i < n;i++){
//         dis[i] = mp[c1][i];
//         if(dis[i] != inf && i != c1){
//             w[i] = w[c1] + city[i];
//             count[i] = 1;
//         }
//     }
//     for(int i = 0;i < n-1;i++){
//         int min = inf;
//         int u;
//         for(int j = 0;j < n;j++){
//             if(book[j] == 0 && dis[j] < min){
//                 min = dis[j];
//                 u = j;
//             }
//         }
//         book[u] = 1;
//         for(int v = 0;v < n;v++){
//             if(mp[u][v] < inf){
//                 if(!book[v] && dis[v] > dis[u] + mp[u][v]){
//                     dis[v] = dis[u]+mp[u][v];
//                     w[v] = w[u] + city[v];//更新救援队的数量
//                     count[v] = count[u]; //更新到v点的路径数目
//                 }
//                 else if(!book[v] && dis[v] == dis[u] + mp[u][v]){
//                     count[v] += count[u];
//                     if(w[v] < w[u] + city[v]){
//                         w[v] = w[u] + city[v];
//                     }
//                 }
//             }
//         }
//     }
// }
// int main()
// {
//     scanf("%d %d %d %d",&n,&m,&c1,&c2);
//     init();
//     for(int i = 0;i  < n;i++){
//         scanf("%d",&city[i]);
//     }
//     for(int i = 0;i < m;i++){
//         int u,v,l;
//         scanf("%d %d %d",&u,&v,&l);
//         mp[u][v] = mp[v][u] = l;
//     }
//     dij();
//     printf("%d %d\n",count[c2],w[c2]);
//     return 0;
// }

// /*
// 对于这一题来说，由于结果不关心最短路径的长度，但是关心最短路径的条数，以及这些最短路径上最大的顶点权重之和，所以一共需要维护一下变量、数组：

// visit[i]标记顶点i是否已经求得最短路径
// city数组记录每个顶点的权重，cost数组记录每条边的权重
// dist[i]记录源点 v0 到顶点 i 的最短距离.若i已经在S中，则该距离即v0到i的最短路径长度；若i不在S中，则该距离即v0只通过S中的顶点到达i的最短路径长度 
// 和Prim算法的最大区别就是Prim-dist对子集S维护，而Dijkstra算法对源点v0维护。
// pathCount[j]维护源点v0到顶点j的最短路径的条数，amount[i]维护源点v0到顶点j的最短路径上的最大顶点权重之和
// 因此本题的关键就是在算法核心部分—松弛（Relax）时维护dist，pathCount，amount这三个数组。

// 假设 j 满足从源点v0通过S中的顶点到 j 的距离dist[j]最小，那么看能否经由 j 到S外的顶点的距离更小。若通过 j 到 k的距离 小于 v0通过之前S中的顶点到 k 的距离，则更新dist[k]的同时，更新pathCount[k]为pathCount[j]，更新amount[k]为amount[j]+city[k]。
// 上面的松弛情况还是比较好理解的，但是不能遗漏另一种情况，如果这两个距离相等怎么办？那就要为pathCount[k]加上pathCount[j]这些路，同时看看amount[k]能否取得更大。
// 注意v0到自己时的情况，下面的代码已经对此优化。
// --------------------- 
// 作者：Lecholin 
// 来源：CSDN 
// 原文：https://blog.csdn.net/lecholin/article/details/71325720 
// 版权声明：本文为博主原创文章，转载请附上博文链接！
// */

// #include "iostream"
// #include "cstring"
// using namespace std;
// const int maxn = 505, INF = 0x3f3f3f3f;

// int city[maxn];  //每个顶点的值
// int cost[maxn][maxn];  //每条边的权重
// int dist[maxn];  //从v0到j的边权重最小值
// int pathCount[maxn], amount[maxn];  //v0到j的最短路径数和累计顶点值(救援队)
// bool visit[maxn];  //标记已经求出最短路径的顶点
// int n, m;

// void init()
// {
//     memset(visit, false, sizeof(visit));
//     for (int i = 0; i<n; ++i)
//     {
//         pathCount[i] = amount[i] = 0;
//         for (int j = 0; j<n; ++j)
//             cost[i][j] = (i == j)? 0: INF;
//     }
// }

// void Dijkstra(int v0) //求v0到各个顶点的最短路径
// {
//     //v0直接到自己最短
//     pathCount[v0] = 1;
//     amount[v0] = city[v0];
//     visit[v0] = true;

//     //生成最初的dist数组
//     for (int i = 0; i<n; ++i)
//     {
//         dist[i] = cost[v0][i];
//         if (dist[i] != INF && i != v0)
//         {
//             amount[i] = amount[v0] + city[i];
//             pathCount[i] = 1;
//         }
//     }

//     for (int i = 0; i < n-1; ++i) //处理剩余n-1个顶点
//     {
//         //找 当前 v0到j的最短路径
//         int min_dist = INF, pos = -1;
//         for (int j = 0; j<n; ++j)
//         {
//             if (!visit[j] && dist[j] < min_dist) //别选已经visit了的顶点！
//             {
//                 min_dist = dist[j];
//                 pos = j;
//             }
//         }
//         visit[pos] = true; //标记访问

//         //更新v0到各点的路径长度
//         for(int j = 0; j < n; ++j)
//         {
//             //松弛，通过pos到j更近
//             if (!visit[j] && dist[pos]+cost[pos][j] < dist[j])
//             {
//                 //通过pos到j
//                 dist[j] = dist[pos] + cost[pos][j]; 
//                 //累加顶点的值
//                 amount[j] = amount[pos] + city[j]; 
//                 //到j的最短路径数即到pos的最短路径数
//                 pathCount[j] = pathCount[pos]; 
//             }
//             //直接到j和通过pos到j的距离相等
//             else if (!visit[j] && dist[pos]+cost[pos][j] == dist[j])
//             {
//                 //增加从pos到j的路径数量
//                 pathCount[j] += pathCount[pos]; 
//                 //更新较大的amount
//                 if (amount[j] < amount[pos]+city[j]) 
//                     amount[j] = amount[pos]+city[j];
//             }
//         }
//     }
//     return;
// }

// int main(int argc, char const *argv[])
// {
//     ios::sync_with_stdio(false);
//     int v0, vt;
//     cin >> n >> m >> v0 >> vt;
//     init();
//     for (int i = 0; i < n; ++i)
//         cin >> city[i];
//     int t1,t2,t;
//     for (int i = 0; i < m; ++i)
//     {
//         cin >> t1 >> t2 >> t;
//         cost[t1][t2] = cost[t2][t1] = t;
//     }
//     Dijkstra(v0);
//     cout << pathCount[vt] << ' ' << amount[vt] << endl;
//     return 0;
// }
// --------------------- 
// 作者：Lecholin 
// 来源：CSDN 
// 原文：https://blog.csdn.net/lecholin/article/details/71325720 
// 版权声明：本文为博主原创文章，转载请附上博文链接！