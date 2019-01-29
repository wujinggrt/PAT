#include <vector>
#include <iostream>
using namespace std;

static const int32_t INF = 0x3F3F3F3F;

struct Highway {
    int32_t dis;
    int32_t cost;
};

int32_t n, m, s, d;
vector<vector<int32_t>> parent;
vector<vector<Highway>> highways;
int32_t min_cost = INT32_MAX;
vector<int32_t> tmp_path;
vector<int32_t> final_path;

void dfs(size_t idx) {
    tmp_path.push_back(idx);
    if (idx == s) {
        int32_t tmp_cost = 0;
        for (int32_t i = tmp_path.size() - 2; i >= 0; --i) {
            tmp_cost += highways[tmp_path[i + 1]][tmp_path[i]].cost;
        }
        if (tmp_cost < min_cost) {
            final_path = tmp_path;
            min_cost = tmp_cost;
        }
        tmp_path.pop_back();
        return ;
    }
    for (auto& e: parent[idx]) {
        dfs(e);
    }
    tmp_path.pop_back();
}

int main() {
    cin >> n >> m >> s >> d;
    highways = vector<vector<Highway>> (n, vector<Highway>(n, Highway{INF, INF}));
    for (int32_t i = 0; i < m; ++i) {
        int32_t from;
        int32_t to;
        int32_t dis;
        int32_t cost;
        cin >> from >> to >> dis >> cost;
        highways[from][to].dis = highways[to][from].dis = dis;
        highways[from][to].cost = highways[to][from].cost = cost;
    }
    parent = vector<vector<int32_t>> (n);
    vector<int32_t> collected(n, 0);
    vector<int32_t> dis(n, INF);
    dis[s] = 0;
    for (size_t i = 0; i < n; ++i) {
        size_t u = -1;
        int32_t min_dis = INF;
        for (size_t v = 0; v < n; ++v) {
            if (collected[v] == 0 && dis[v] < min_dis) {
                u = v;
                min_dis = dis[v];
            }
        }
        if (u == -1) {
            break;
        }
        collected[u] = 1;
        for (size_t v = 0; v < n; ++v) {
            if (collected[v] == 0 ) {
                if (dis[v] > dis[u] + highways[u][v].dis) {
                    dis[v] = dis[u] + highways[u][v].dis;
                    parent[v].clear();
                    parent[v].push_back(u);
                } else if (dis[v] == dis[u] + highways[u][v].dis) {
                    parent[v].push_back(u);
                }
            }
        }
    }
    dfs(d);
    bool first = true;
    int32_t min_dis = 0;
    for (auto iter = rbegin(final_path); iter != rend(final_path); ++iter) {
        if (first) {
            first = false;
        } else {
            cout << " ";
            min_dis += highways[*(iter - 1)][*iter].dis;
        }
        cout << *iter;
    }
    cout << " " << min_dis << " " << min_cost;
}