[PAT 1010 Radix (25)](https://blog.csdn.net/baidu_25107219/article/details/46700669)

1，首先求目标数据进制，这个进制在任何条件下面都不能小于2，最大多少呢，不能局限于36，请想象多大都是有可能的，有多大，这么大！所以必须用long long int数据类型，这个一开始一直是被遗忘的角落。

2，由于数据搜索范围太大，穷举法一个for循环显然太慢了，肯定要超时的，最终就选则二分法查找。那么问题来了，二分法查找搜索上下边界是多少呢。这个好办，目标待求字符串的最小进制一定要比它所包含字符最大值还要大1，例如N2="456ad"，最大字符是'd'，所以最小应该是13+1=14,，这就对了吗？当然不对万一，我输入的N2="0"呢

最大字符'0'，然后0+1=1，这是不对的，最小值是2才对。那么它的上限是多少呢，上限当然不能超过另外一个数据的十进制大小，因为N2不为0情况下，最小个位数都是1，如果它的进制再超过N1的十进制数了的话，它在十进制下的数也就比N1还要大，不符合要求。

3，如果一开始，输入两个数据N2最小进制都比N1的十进制数据还要大的话，怎么办呢。N2最小进制的最大数据也就36，出现这种情况也就说明N1在十进制下肯定比36小，二分查找上限就不能是N1在十进制时候的数了，应该改为36。

几个特俗测试点容易被遗忘 0 0 1 100以及12 c 1 10


--------------------- 
作者：快点er 
来源：CSDN 
原文：https://blog.csdn.net/baidu_25107219/article/details/46700669 
版权声明：本文为博主原创文章，转载请附上博文链接！

[another](https://blog.csdn.net/CV_Jason/article/details/80993283)

那么只要是取值为负的，全部是上溢，基数取得过大了。 
