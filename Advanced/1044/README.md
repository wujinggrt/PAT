# Shopping in Mars

it cannot be taken back.

DP,子序列。

记录chain[i]的前n项和，然后取舍。可以二分法，可以dp。。。

#### 使用的方法

使用i, j记录序列起始：

    3 2 1 5 4
    |       j:5
    i:1

    3 2 1 5 4 6       3 2 1 5 4 6
    |         j:6 =>        |   j:6   
    i:1                     i:4

j使用外层for，先固定j，然后向左寻找tmp_sum >= m。并且使用diff记录他们的差，找出最靠近m的值。