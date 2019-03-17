# Reversing Linked List

题意，每K个node为一组，需要翻转这一组K，然后继续到下一组。

主要思路为：

首先通过map，按照访问顺序走一遍，保存在vector里面，然后在从vector每k个的进行操作。

使用三个变量， prev = "-1"s or nullptr,总之为末尾的标志, cur = head, next。

1. 先从cur操作，让next = cur->next，保存下一个结点，避免丢失。
2. cur->next = prev，翻转这个结点完成。
3. prev = cur, cur = next，进行下一次轮转。

如果next == "-1"s，break，完成翻转。

更好的办法，在用vector存储原来的顺序之后，不进行那么复杂的翻转。只需要输出下一个点的address就可以了。也就是一个规律。

边界case：

1. 最后一个测试点：输入的N个结点，有某些不在linked list上。所以不要用n来判断，用nodeIters.size()，代码的可靠性。
2. case 1 5老是不过。