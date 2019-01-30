# Longest Symmetric String

回文。

从左遍历，在这个点，向backward, forward延伸，查看他们是否相等。然后使用一个max_cnt记录。

特殊case：测试点5，输入单个字符，输出1。

????更正这个特殊case的s.cpp反而测试点3过不了，cp.cpp没有更正，却AC。特殊case：比如111，奇数个。老算法一直会判断两个相连的类型("aa"，不包含"aba"类型。latter为奇数的case),output:2。改进，优先考虑latter。a111a也不行,output:2。

猜测，aba aa，这两种类型，考虑aaa 还是aa要多一些，所以这种情况aaa则需要进行两次比较（比较"aaa"中后两个"aa"，和"aaa"前一个和后一个a）。

a1111则按照上面aba和aa两种策略得到3和4.

测试点4：if str不为空，输出至少为1，因为单个字符。