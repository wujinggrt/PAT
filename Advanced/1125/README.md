# Chain the Ropes

After each chaining, the lengths of the original two segments will be halved.

两个原来的会被打折。

ceiling division by 2:

可以判断是否能够被整除。也可以使用 (dividand +1) / 2 -> (3 + 1) / 2, 

两段绳子对折，再如下图所示套接在一起。

越是早加入绳子长度中的段，越要对折的次数多，所以既然希望绳子长度是最长的，就必须让长的段对折次数尽可能的短。所以将所有段从小到大排序，然后从头到尾从小到大分别将每一段依次加入结绳的绳子中，最后得到的结果才会是最长的结果。

所有都要合起来，我只不过需要判断顺序。