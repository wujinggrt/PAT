# Highest Price in Supply Chain

第二行给出的数是，第 i 个数是第 i 个 member 的 supplier， 然后利用这个来重新建图， or dfs.

需要找出最长的路径。

不能走重复的路，否则超时。可以使用` map `记录，也可在使用结点上的域来记录。

使用一个` map `来记录访问过的地方，然后如果进货的` id `在` map `中，就可以直接从里面拿出来。类似` dp `。好像这题就是` dp `。。。