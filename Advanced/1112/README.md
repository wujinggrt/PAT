# Stucked Keyboard

but s is not even though it appears repeatedly sometimes. 

s 有时候不会重复，所以是刻意重复的。那么就需要保存好的 char。

坏掉的键要按照检测的时候的顺序打印。

使用一个 map 来记录键的可能是好坏，在使用一个数组来确定键肯定不是坏的。

顺序输出坏的时候，就循环一遍再加上 set。

输出的时候，如果是坏的，那么就跳过 k - 1 个。