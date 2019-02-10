# Prime Factors

给定的测试数字都是可以质因数来因式分解的。

遍历素数，从最小的2开始，查看是否能够整除2^prime_factor, for prime_factor = 1,2,3...。如果能整除，那么2的prime_factor次方就是其中一个因数。同理，遍历到下一个素数。

如果cout，printf最后没有换行（\n），那么紧跟其后如果有死循环，就会不显示出来。除非在死循环之前有出现过\n的输出。

```C++    
    // 并不会输出输入的num
    cin >> num;  
    cout << num << "=";
    auto ii = 3;
    for (;;);
```