# Travelling Salesman Problem

not a single cycle: 重复的元素只有一个

TS cycle: 重复的元素超过一个

TS simple cycle: 回到起点， start == end，那么就可以使用 cycle 访问每一个city. visits every city; 访问了所有城市.

不要简单的 break，需要处理完 buffer 上的数据，不然后面会读取到这儿。导致段错误。

tips: 应该把这种和下一个数据进行操作的保存到一个 vector，方便操作。不要直接判断。不然代码很麻烦，难看懂。

思路：使用 vector 来存储后面的 k 条路径上的城市，然后判断首尾和联通关系。再用 set 来保存非重复的数据，判断是否访问所有城市。

三个路的特点：
1. TS simple cycle: 访问了所有的城市，起点访问了两次。一共访问了 n + 1 个city。
2. TS cycle: 访问了所有城市(visited_num > n + 1)，回到起点。
3. Not a TS cycle: else。道路不同，或者没有环，没有回到起点城市。或者没有访问所有的城市。