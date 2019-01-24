#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 99999999;
int cmax, n, sp, m;
int minNeed = inf, minBack = inf;
int e[510][510], dis[510], weight[510];
bool visit[510];
// pi or parent
vector<int> pre[510];
vector<int> path, temppath;
void dfs(int v) {
    temppath.push_back(v);
    // 到头了
    if(v == 0) {
        int need = 0, back = 0;
        // 更新need，back
        // 因为是从PBMC出发，所以从temppath的最后一个元素向前推。
        // send和back只能够按照从PBMC到sp的路径上前推，所以有这个for的顺序。
        // 往回带不行，只能够往前送，因为是只能够从PBMC往目的地走的。
        for(int i = temppath.size() - 1; i >= 0; i--) {
            int id = temppath[i];
            if(weight[id] > 0) {
                back += weight[id];
            } else {
                if(back > (0 - weight[id])) {
                    back += weight[id];
                } else {
                    need += ((0 - weight[id]) - back);
                    back = 0;
                }
            }
        }
        if(need < minNeed) {
            minNeed = need;
            minBack = back;
            path = temppath;
        // 相同的从PBMC送出bike数量，然后选择
        // minimum number of bikes that we must take back to PBMC. 的路径
        } else if (need == minNeed && back < minBack) {
            minBack = back;
            path = temppath;
        }
        temppath.pop_back();
        return ;
    }
    // dfs v 的前一个，parent
    /*
    for (auto& e: pre[v]) {
        dfs(e);
    }
    */
    for(int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    temppath.pop_back();
}
int main() {
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        weight[i] = weight[i] - cmax / 2;
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%d", &e[a][b]);
        e[b][a] = e[a][b];
    }
    dis[0] = 0;
    for(int i = 0; i <= n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j <= n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v <= n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                    // 说明存在距离station更短的路径，clear
                    pre[v].clear();
                    // 思路点：
                    // pre记录v经过的前一个点,pre or parent,即是这个u
                    // 相同的dis中，最短路径上的可能选择的点
                    // 在最后来进行确认
                    // 也就是，需要在这些v之上来进行dfs出最短路径
                    // 最后比较
                    pre[v].push_back(u);
                } else if(dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    //由最后的点来不断搜寻pre。看看他是否只有一个可能的parent
    // 否则，遍历下。
    dfs(sp);
    printf("%d 0", minNeed);
    for(int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d\n", minBack);
    return 0;
}