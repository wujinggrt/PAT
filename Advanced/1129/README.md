# Recommendation System

there is no output for the first item. 第一个不用输出。

第 i 个客户访问商品的时候，参考前面 i - 1 个客户访问商品的频率。

使用 set 来保存商品 id 和被访问次数，set 可以达到排序功能。在使用 map 来完成出现次数的索引。
