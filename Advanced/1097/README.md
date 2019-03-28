# Deduplication on a Linked List

Hash map 的使用，保存每个地址，然后再用 Hash set 来判断是否这个值已经存在。只需要注意逻辑就 OK。

这儿有一个问题，就是容器的 size() 方法返回的是 size_t 类型的，无符号。当为 0 的时候，-1 就不会得到 -1，而是最大值。所以应该 cast. 