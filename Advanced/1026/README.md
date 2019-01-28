# Table Tennis

参考博客[pat1026Table Tennis (30)](https://blog.csdn.net/loststephon/article/details/48899253)

启示：先从容易下手的特殊情况（等待的只有vip or ordinary）考虑，降低问题的复杂度，然后一步一步conquer.

测试点3：在21：00及之后来的顾客需要处理。

测试点4考察的是"It is assumed that every pair of players can play for at most 2 hours."

测试点8则是"The waiting time must be rounded up to an integer minute(s)." 就是说，等待时间是通过四舍五入取整((waiting_time+30)/60)来计算的，而非向上取整(ceil).

## 分析

#### 数据结构

时间使用秒来表达，player分为两个vector，table分为一个vector。

players的存储分为vips, ordinaries。存在vector。如果arrive在21:00及之后，则不存储。

player使用make_heap和pop_heap来查找，相当于优先队列。

tables存储在一个vector，然后保存的成员是open_time，也就是能够使用这台桌子的时间，可以根据这个时间来判断什么时候上桌。其次，使用一个flag来确定是否为vip桌子。

#### 算法

当两个players都不全为空的的时候，也就是有人在21点之前来球馆的情况：

首先查找最先open的table，可能现在open，也可能需要过一会儿。同时，查找最近将要open的vip桌子，用处为当都为空桌子，vip优先用它。

根据即将open的桌子来解决问题：

然后选出即将play的player，考虑的结果为一下情况（2的问题转换b部分很巧妙）：

1. 特殊情况，只有vip用户 or ordinary用户排队，也就是容易考虑的情况。直接从等待的vector中选择front()来serve。如果这个特殊情况不单独列出来，那么在2，3情况需要考虑到选择的用户是否为空，为空则补其他用户。
2. 如果两者同时在，查找最先open的table为VIP桌，情况分为:<br >
    a. vip用户比普通用户先到，自然是vip用户先使用。<br >
    b. 当前vip桌子还没有结束，没有open，不管vip是在普通用户之前还是之后。那么vip用户在等到vip桌子open之后，能够优先使用。<br >
    c. otherwise, 普通用户作为下一个上桌的player。
3. 最先open的桌子为普通桌子，那么如果vip在普通用户前来，vip使用；反之，普通用户使用。

接下来需要更新桌子，这儿需要注意，如果是vip用户，且vip桌子同时open，那么会优先使用vip桌子。