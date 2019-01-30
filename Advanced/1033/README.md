# To Fill or Not to Fill

[借鉴的博客](https://www.cnblogs.com/chenxiwenruo/p/6735382.html)

贪心算法：首先计算出加满油能跑多远(max_forward)。从跑到max_forward的范围里，找到最近的比当前这个station的price便宜的地方。不是最便宜的，否则不是贪心了。如果max_forward范围内价格都比当前站要大，那么加满油，到达其中最便宜的station，再继续选择。

选择最终战为price:0, dis:d，作为最后一站，可以方便计算。此时cur超出范围，break循环。