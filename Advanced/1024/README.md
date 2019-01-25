# Palindromic Number

使用reversed_num == num来判断。

reverse numbers可能出现的情况需要考虑:

第一次给的数据就是Palindromic Number，那么代码的设计需要考虑到这个地方，循环就是：

1. 先取反
2. 比较是否Palindromic
3. plus，得到新的num。此时才算是运行了一次plus运算。

第三步最多执行K次，那么中断则从2，break。