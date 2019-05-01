# Sum of Number Segments

找规律：

    1               \
    1 * 2            |
    1 * 2 * 3        | 第一层    
    1 * 2 * 3 * 4   / 
        2              第二层
        2 * 3           
        2 * 3 * 4           
            3           
            3 * 4
                4

可以看到，1 只在第一层出现，并且出现 4 次，也就是 1 * 4 次。 2 在第 1， 2 层出现，每层出现 4 - 1 = 3 次。所以 2 * 3 = 6 次。往后规律如此。

## 一个小坑，类型转换?

```C++
// wrong
// ans += i * (n - i + 1) * nums[i];
// yes
ans +=  nums[i] * i * (n - i + 1);
```