# Stack

PeekMedian: former if n is even.

#### multiset

使用multiset来完成，红黑树。[ref](https://blog.csdn.net/cstopcoder/article/details/24496853)

lower(T, comparetor = greater<T>)和upper为两个multiset，

// 其中，upper == lower or upper + 1 == lower，至少维护这个状态，因为找的是former，或者是median，只需要begin(lower)
// 这样的话，lower.begin()就是我们要找的答案了。使用begin方便我们查找，比end - 1方便得多

stack可能为空，那么mid需要调整。

#### 树状数组

[树状数组](https://blog.csdn.net/flushhip/article/details/79165701)