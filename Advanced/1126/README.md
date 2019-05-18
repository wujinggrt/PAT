# Eulerian Path

Eulerian circuit starts and ends on the same vertex. 

Eulerian path is a path in a graph which visits every edge exactly onces

connected graphs with all vertices of even degree have an Eulerian circuit, and such graphs are called Eulerian.

 graph that has an Eulerian path but not an Eulerian circuit is called semi-Eulerian. 

可以使用 map 后者 set 来判断是否遍历完全。

It has been proven that connected graphs with all vertices of *****even** degree have an Eulerian circuit, and such graphs are called Eulerian. If there are exactly two vertices of **odd** degree, all Eulerian paths start at one of them and end at the other. A graph that has an Eulerian path but not an Eulerian circuit is called semi-Eulerian. 

需要判断 degree 就可以,也就是每一行有多少。恰好无向图，省去了出入度的区别。然后在判断奇偶。但是需要判断是否不是连通图的话，输出 Non 选项。DFS 解决。
