# Vertex Cover

*****each edge** of the graph is incident to at least one vertex of the set

出现的所有 node 必须至少是每一个 edge 的一端。

给每一条边编号（每两个端点决定一条边，所以就会有出现 m 条边，就算他们是连起来成一条更长的）。然后在使用一个 vector 来作为 query 的时候，是否遍历到了所有的边。
