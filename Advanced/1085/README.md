# Perfect Sequence

感觉是dp。怎么找到方程呢？

类似lcs的思路吗？

找到最长的，能够作为这样的序列， max <= min * p.

不是dp，没那么复杂，排序，但是需要遍历每一个元素，对每一个元素使用一定的width，最后就输出这个width。