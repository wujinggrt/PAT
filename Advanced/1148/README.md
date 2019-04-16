# Werewolf - Simple Version

仅仅有一个狼说谎。找出说谎的？

使用有向图，然后查找环？or 拓扑排序？

逻辑题。

1 -> -2
2 -> +3
3 -> -4
4 -> +5
5 -> +4

1, 4 是狼人：

## #1 说谎， 另外一个没说谎：

1 说谎，另外一个则是实话： 1 true:=> 2 不是狼人; 

1. 假设 3 是狼人，他没有说谎 => 4 就是狼人，得出狼人数量 > 2, false
2. 假设 4 是狼人 => 5 is human， OK 狼人数量 == 2.
3. 假设 5 是狼人 => 4 is human, OK 狼人数量 == 2。

有两种情况。题意 : If there are more than one solution, you must output the smallest solution sequence. 那就输出 1 4.

## #1 没说谎， 另外一个说谎： 

1 => 2 is wolf. 2 说谎, 3 is wolf => 狼人数量 > 2, false.

这种情况不存在。

使用哈希表记录每一个人的状态，如果被改变了，也就是冲突了。dfs ?

只有狼人知道狼人是谁，人不知道狼人的身份，所以人可能会判断错误。那么穷举：

1 是狼人，他说谎的情况：另外一个狼人就会说实话。
1 是狼人，他说实话的情况：另外一个狼人就会说实话。

## 重新审题

at least one 至少有一个人说谎，但是不全是狼人在说谎，然后枚举。

也就是说谎的人包含人类。可能狼人说谎，可能没说谎。假设两个狼人，然后无视狼人的发言，找出说谎的人。所以条件不全是狼人在说谎给的信息 OK.

at least one but not all the werewolves were lying, and there were exactly 2 liars.. **仔细审题，不要放过细节 hint**。一个狼人和一个人类在说谎。

```C++

for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
        // 1 is human
        vector<int> id(n + 1, 1); 
        id[i] = id[j] = -1;
        vector<int> lier;
        for (int k = 1; k <= n; ++k) {
            // 已经假设了两个狼人了，就可以验证说谎的人了
            int refer_k = abs(states[k]);
            // k 认为他的身份与实际身份
            if ((states[k] * id[refer_k]) < 0) {
                // 说谎
                lier.push_back(k);
            }
        }
        // 一个狼人，一个人 -1 + 1
        if (lier.size() == 2) {
            if (id[lier.front()] + id[lier.back()] == 0) {
                cout << i << " " << j << "\n";
                return 0;
            }
        }
    }
}

```