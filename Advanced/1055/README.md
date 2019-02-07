# The World's Richest

首先根据年龄排序，然后找到年龄阶段，lower, upper_bound, 之后再copy然后sort一次，在print前m个。

测试点3运行超时。因为string。

另一种算法，直接按照目标输出的排，就是:

The outputs must be in non-increasing order of the net worths. In case there are equal worths, it must be in non-decreasing order of the ages. If both worths and ages are the same, then the output must be in non-decreasing alphabetical order of the names.

这样排序之后，然后每一个test就进行一次O(n)遍历，然后年龄符合，可以输出。