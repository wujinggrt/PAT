# Splitting A Linked List

使用三个 vector 分别记录负数，0,k, 大于 k 的 addr，然后在输出下一个。需要注意其中某一项都有可能为 0 个，影响输出格式，所以需要考虑 0 的情况，所以设置 first 代表第一个输出。
