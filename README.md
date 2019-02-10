# PAT
With C++ 11 and STL.

## Advanced

### List

|No.|Title|File|Description|Tag|
|---|---|---|---|---|
|1017|Queueing at Bank|[C++](./Advanced/1017)|优先队列，时间用秒表达|-|
|1018|Public Bike Management|[C++](./Advanced/1018)|dfs, dijkstra + dfs|-|
|1019|General Palindromic Number|[C++](./Advanced/1019)|进制转换|-|
|1020|Tree Traversals|[C++](./Advanced/1020)|后序、中序遍历还原二叉树，层序遍历|-|
|1021|Deepest Root|[C++](./Advanced/1021)|DFS(穷举与两次查找)，并查集|-|
|1022|Digital Library|[C++](./Advanced/1022)|map + set的简单使用，lambda替代函数|-|
|1023|Have Fun with Numbers|[C++](./Advanced/1023)|string手动计算乘法，进位可能多1|-|
|1024|Palindromic Number|[C++](./Advanced/1024)|string类型的数字加法运算|-|
|1025|PAT Ranking|[C++](./Advanced/1025)|排序|-|
|1026|Table Tennis|[C++](./Advanced/1026)|时间表达为秒，桌子开始服务的时间|分析问题，分解问题要求较高，需要逻辑和清晰的思路，转化问题|
|1027|Colors in Mars|[C++](./Advanced/1027)|简单的进制转化|-|
|1028|List Sorting|[C++](./Advanced/1028)|std::sort|-|
|1029|Median|[C++](./Advanced/1029)|内存，cin/cout的效率低，问题转换|-|
|1030|Travel Plan|[C++](./Advanced/1030)|dijkstra+dfs, or dfs，1018同类|-|
|1031|Hello World for U|[C++](./Advanced/1031)|字符处理|-|
|1032|Sharing|[C++](./Advanced/1032)|hash map，寻址|-|
|1033|To Fill or Not to Fill|[C++](./Advanced/1033)|贪心算法|-|
|1034|Head of a Gang|[C++](./Advanced/1034)|map的信息来建立Graph，30分||
|1035|Password|[C++](./Advanced/1035)|简单的字符串替换|-|
|1036|Boys vs Girls|[C++](./Advanced/1036)|简单数据处理|-|
|1037|Magic Coupon|[C++](./Advanced/1037)|排序，取舍|-|
|1038|Recover the Smallest Number|[C++](./Advanced/1038)|字符串的排序，ab < ba，问题转化，观察关系|-|
|1039|Course List for Student|[C++](./Advanced/1039)|map,set,cin效率bottleneck|-|
|1040|Longest Symmetric String|[C++](./Advanced/1040)|最长回文|-|
|1041|Be Unique|[C++](./Advanced/1041)|map + flag|-|
|1042|Shuffling Machine|[C++](./Advanced/1042)|map的使用|-|
|1043|Is It a Binary Search Tree|[C++](./Advanced/1043)|二叉树，unique_ptr，还原|-|
|1044|Shopping in Mars|[C++](./Advanced/1044)|子序列|-|
|1045|Favorite Color Stripe|[C++](./Advanced/1045)|最长共同子序列，DP|-|
|1046|Shortest Distance|[C++](./Advanced/1046)|距离总和，O(n)|-|
|1047|Student List for Course|[C++](./Advanced/1047)|unordered_map + vector + sort|-|
|1048|Find Coins|[C++](./Advanced/1048)|two sum, map|-|
|1049|Counting Ones|[C++](./Advanced/1049)|two sum, map|-|
|1050|String Subtraction|[C++](./Advanced/1050)|unordered_set|-|
|1051|Pop Sequence|[C++](./Advanced/1051)|模拟stack，还原，找规律，升序和降序|-|
|1052|Linked List Sorting|[C++](./Advanced/1052)|map来建立链表，遍历后ptr to node压栈，sort|-|
|1053|Path of Equal Weight|[C++](./Advanced/1053)|tree,dfs,回溯和剪枝，递归lambda|-|
|1054|The Dominant Color|[C++](./Advanced/1054)|map，cin bottleneck|-|
|1055|The World's Richest|[C++](./Advanced/1055)|选择性排序，超时|-|
|1056|Mice and Rice|[C++](./Advanced/1056)|队列，排名|-|
|1057|Stack|[C++](./Advanced/1057)|multiset, or 树状数组|-|
|1058|Hogwarts|[C++](./Advanced/1058)|进制|-|
|1059|Prime Factors|[C++](./Advanced/1059)|质数，因式分解，遍历|-|

### 总结

1. Adjacent Matrix在某些情况可能内存超出限制。
2. 时间->用秒方便
3. 解析二叉树最好使用struct Node {ptr l, r;};
4. 30分的题需要找规律，暴力穷举解决不了。

## Basic

|No.|Title|File|Description|Tag|
|---|---|---|---|---|
|**1001**|害死人不偿命的(3n+1)猜想|[C++](./Basic/1001.cpp)| \ | 枚举 |
|**1002**|写出这个数|[C++](./Basic/1002.cpp)| \ | |
|**1003**|我要通过！|[C++](./Basic/1003.cpp)| \ | |
|**1004**|成绩排名|[C++](./Basic/1004.cpp)| \ | |
|**1005**|继续(3n+1)猜想|[C++](./Basic/1005.cpp)| \ | |
|**1006**|换个格式输出整数|[C++](./Basic/1006.cpp)| \ | |
|**1007**|素数对猜想|[C++](./Basic/1007.cpp)| \ | |
|**1008**|数组元素循环右移问题|[C++](./Basic/1008.cpp)| \ | |
|**1009**|说反话|[C++](./Basic/1009.cpp)| \ | |
|**1010**|一元多项式求导|[C++](./Basic/1010.cpp)| \ | |
|**1011**|A+B 和 C|[C++](./Basic/1011.cpp)| \ | |
|**1012**|数字分类|[C++](./Basic/1012.cpp)| \ | |
|**1013**|数素数|[C++](./Basic/1013.cpp)| \ | |
|**1014**|福尔摩斯的约会|[C++](./Basic/1014.cpp)| \ | |
|**1015**|德才论|[C++](./Basic/1015.cpp)| \ | |
|**1016**|部分A+B|[C++](./Basic/1016.cpp)| \ | |
|**1017**|A除以B|[C++](./Basic/1017.cpp)| \ | |
|**1018**|锤子剪刀布|[C++](./Basic/1018.cpp)| \ | |
|**1019**|数字黑洞|[C++](./Basic/1019.cpp)| \ | |
|**1020**|月饼|[C++](./Basic/1020.cpp)| \ | |
|**1021**|个位数统计|[C++](./Basic/1021.cpp)| \ | |
|**1022**|D进制的A+B|[C++](./Basic/1022.cpp)| \ | |
|**1023**|组个最小数|[C++](./Basic/1023.cpp)| \ | |
|**1024**|科学计数法|[C++](./Basic/1024.cpp)| \ | |
|**1025**|反转链表|[C++](./Basic/1025.cpp)| \ | |
|**1026**|程序运行时间|[C++](./Basic/1026.cpp)| \ | |
|**1027**|打印沙漏|[C++](./Basic/1027.cpp)| \ |递归|
|**1028**|人口普查|[C++](./Basic/1028.cpp)| \ ||
|**1029**|旧键盘|[C++](./Basic/1029/1029.cpp)| \ ||
|**1030**|完美数列|[C++](./Basic/1030/1030.cpp)| \ |运行效率、分块查询|

