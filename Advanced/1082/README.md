# Read Number in Chinese

每四位分为一组，然后输出。比如1 2345 6789, 10 0800

遇到ling的情况，推迟到输出另外一个数字的时候才print它，如果之后一直为0。那么久就不会输出ling了。

然后在设置一个print这一个四位的flag，决定是否print他。比如:10 0000 直接输出yi Shi Wan，然后这个输出后面四位10的flag为false，因为没有输出。

[参考了博客](https://blog.csdn.net/hy971216/article/details/81153487)