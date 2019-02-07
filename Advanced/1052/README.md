# Linked List Sorting

使用unordered_map来建立每一个node，为了之后方便，这些node也保存着自己的address和prev，next。

然后根据head遍历链表，遍历同时把这些node存在vector，随后sort。最后输出的时候，输出每一个当前address和下一个node的address作为next。

但是测试点3会超时，这儿是难点。vector换做指针后AC。 