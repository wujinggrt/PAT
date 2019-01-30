# Head of a Gang

大于K的无向图？

each other，每个人都联系，total relation weight, 且团体大于2人。

    AAA <-> BBB : 30
    AAA <-> CCC : 40
    70

    GGG <-> FFF :30
    GGG <-> HHH :20
    HHH <-> FFF :10

    D - E

    A - B   G - F
    |       \   /
    C         H

连通分量，连通分量的大小。

使用map来保存每个人与其他人联系记录，weight，然后遍历set，加起来超过2人，total超过k，则为gang。

测试点2：The output must be sorted according to the alphabetical order of the names of the heads.

dfs来判断有多少个component，也就是大于等于3个人的联系人团伙。

#### 分析

使用map，有序的map来保存每一个caller，然后他们都可以对应到一个序号，使用这个序号来建立一个无向图。

然后dfs，每一个环就有可能是gangs cluster，然后在最后判断他们的大小，relations weight来删除他们。

最后对gangs中，找到最大的total（这个记录在map了，直接遍历，访问map就可以拿到），然后在对名字排序。