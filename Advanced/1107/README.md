# Social Clusters

    2 4 6 8 号
    3 5 7 号 5 和 3
    1 号 孤立

使用 map 和 set 的组合来保存这些特性？或者并查集来实现。

先扫描第一格，然后记录下他的爱好，所有的爱好作为这个组的标签。然后下一个，如果有一个属于其中那么同属于这一组，否则他的所有标签全部拿出来，形成新的组。这样到最后就完成分 clusters.

测试点 1， 4 过不去, 因为有些还没有更新 root， 指向的 root 还没有指向他自己。但是更滑输出侧率，也就是使用 is_root 的 vector 来辅助之后, AC.


只要有一个爱好相同，就归到并查集中的一类。那么后面相同的爱好的人，就会被 Union 到第一个拥有这个爱好的人的 set 中，这第一个人属于哪个 set，这些人也就属于哪个 set 了。每次 Union 都会让现有的 Parent 指向自己。

还需要一个来记录第一格爱好的人。