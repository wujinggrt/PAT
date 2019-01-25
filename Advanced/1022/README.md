# Digital Library

结构体，全部使用string来存储，然后使用algorithm的find_if和string::find，完成查找的功能。但是这个方法老师在最后三个测试点过不了，放弃。

#### 使用`unordered_map + set`，其中set有序，所以完成id的有序输出。

map保存着title，author等等数据，然后对应着id的set，可以通过访问他们(`titles.find(title)`)得到结果。