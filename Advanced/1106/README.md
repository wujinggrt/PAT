# Lowest Price in Supply Chain

dfs，找寻最短路径到 root.

每一行代表一个商贩，使用 AdjacentMatrix 会超内存，需要 AdjacentList.

```C++
vector<vector<int>> chains(n);
for (auto& chain: chains) {
    int k;
    cin >> k;
    chain = vector<int>(k);
    for (int i = 0; i < k; ++i) {
        int j;
        cin >> j;
        chain[i] = j;
    }
}
```