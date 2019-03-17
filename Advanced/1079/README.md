# Total Sales of Supply Chain

从一个supplier以P进货，然后sell或者distribute 1 + r% higher than P.

只有retailer面向customer，也就是终端。也就是 1 + r% 的辗转数次方。判断retailer的机制为，graph[retailer][retailer] != INF.

到最后，我们需要的事那个retailer贩卖的价格，所以需要从retailer回溯到root。

题目保证每个retailer只有一个进货distributor。

使用Adjacent Matrix会内存flow，需要使用Adjacent List.

可以使用从retailertrack到root。也可以从root使用dfs到每一个retailer。