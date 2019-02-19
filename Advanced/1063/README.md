# Set Similarity

总体简单。读题，使用map来保存每一个numbers的个数？and using set to calculate the distinct numbers？

使用set来保存，可以剔除相同的number。然后在检索的时候，遍历其中一个，然后使用find来确认重复。

如果是复制到新的total的话，会超时，值遍历，不复制。