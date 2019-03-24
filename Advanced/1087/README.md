# All Roads Lead to Rome

从start出发到Roma，cost最小，happiness最多。

借助map映射到城市下标，Dijk。

Dij中使用vector来保存，当时相同dist的决策，然后dfs，然后从dest回溯到start。

从dest track到start的思路是dfs(dest)，然后利用一个tmp_path记录，然后每次dfs完了就pop_back。如果到start了，那么就处理每一个tmp_path上的结点，然后在判断是否更新（copy）到path。

```C++
function<void(int)> dfs = [&] (int idx) {
    tmp_path.push_back(idx); // 一开始压入这个结点
    if (idx == 0) {
        ++num_different;
        // 他们的cost都相同
        // 需要计算happiness
        int happiness = 0;
        for (auto city: tmp_path) {
            happiness += cities[city].happiness;
        }
        if (max_happiness < happiness) {
            max_happiness = happiness;
            path = tmp_path;
        } else if (max_happiness == happiness) {
            if (path.size() > tmp_path.size()) {
                path = tmp_path;
            }
        }
        tmp_path.pop_back();
        return;
    }
    for (auto pos: parent[idx]) {
        dfs(pos);
    }
    tmp_path.pop_back(); // pop掉
};
```