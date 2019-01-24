#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

static const int32_t INF = 0X3F3F3F3F;

struct Stations {
    vector<int32_t> bikes;
    vector<vector<int32_t>> edges;

    Stations() = default;
    Stations(int32_t count) 
        : bikes{vector<int32_t>(count)}, 
        edges(count, vector<int32_t>(count, INF)) {}
};

Stations stations;

vector<int32_t> dis;
vector<vector<int32_t>> parent;
vector<int32_t> collected;

int32_t count_max;
int32_t n;
int32_t s_p;
int32_t m;

// 先send最小，如果send相同，则比较take
int32_t min_send = INF;
int32_t min_take = INF;
vector<int32_t> path;
vector<int32_t> tmp_path;

/************************************************************
 * 使用dijkstra + dfs方法,7ms
************************************************************/

void dijkstra() {
    // find shortest, 动态维护的优先队列
    dis = vector<int32_t> (n + 1, INF);
    parent = vector<vector<int32_t>> (n + 1);
    collected = vector<int32_t> (n + 1, 0);
    dis[0] = 0;
    for (int32_t i = 0; i < n + 1; ++i) {
        int32_t u = -1;
        int32_t min_time = INF;
        // 找到最小的，而且没有收集起来
        for (int32_t v = 0; v < n + 1; ++v) {
            if (collected[v] != 1 && min_time > dis[v]) {
                u = v;
                min_time = dis[v];
            }
        }
        if (u == -1) {
            break;
        }
        collected[u] = 1;
        for (int32_t v = 0; v < n + 1; ++v) {
            if (dis[v] > dis[u] + stations.edges[u][v]) {
                dis[v] = dis[u] + stations.edges[u][v];
                parent[v].clear();
                parent[v].push_back(u);
            } else if (dis[v] == dis[u] + stations.edges[u][v]) {
                // cout << "Same dis from " << u << " to:" << v << "\n";
                parent[v].push_back(u);
            }
        }
    }
}

void dfs(int32_t station_no) {
    tmp_path.push_back(station_no);
    if (station_no == 0) {
        // 0 (PBMC) 不需要计算send, take
        tmp_path.pop_back();
        // printf("Same dis paths\n");
        int32_t send = 0;
        int32_t take = 0;
        for (int32_t i = tmp_path.size() - 1; i >= 0; --i) {
            int32_t station = tmp_path[i];
            // 需要从PBMC来send，从之前的站中带出来的bike不够了
            if (stations.bikes[station] + take < 0) {
                send += -(stations.bikes[station] + take);
                take = 0;
                // printf("stations:%d send:%d\n", station, send);
            // 更新当前站take回去的数量，或者补回去下一站后剩余量
            } else {
                take += stations.bikes[station];
                // printf("stations:%d take:%d\n", station, take);
            }
        }
        // printf("send:%d take:%d\n", send, take);
        if (
            (min_send > send) ||
            (min_send == send && min_take > take)
        ) {
            min_send = send;
            min_take = take;
            path = tmp_path;
        }
        return;
    }
    for (auto& e: parent[station_no]){
        dfs(e);
    }
    // backtracking
    tmp_path.pop_back();
}

void dijkstra_dfs() {
    dijkstra();
    dfs(s_p);
    printf("%d 0", min_send);
    for (int32_t i = path.size() - 1; i >= 0; --i) {
        printf("->%d", path[i]);
    }
    printf(" %d\n", min_take);
}


/************************************************************
 * 使用dfs方法,7ms
************************************************************/
int32_t total_dis = INF;
int32_t tmp_total_dis = 0;
int32_t send = 0;
int32_t take = 0;

void dfs_aux(int32_t station_no);

// from PBMC(0) to dst(s_p)
void dfs_all() {
    collected = vector<int32_t> (n + 1, 0);
    dis = vector<int32_t> (n + 1, INF);
    dfs_aux(0);
    printf("%d 0", min_send);
    for (int32_t i = 1; i < path.size(); ++i) {
        printf("->%d", path[i]);
    }
    printf(" %d\n", min_take);
}

void dfs_aux(int32_t station_no) {
    tmp_path.push_back(station_no);
    collected[station_no] = 1;
    if (station_no == s_p) {
        if (total_dis > tmp_total_dis) {
            min_send = send;
            min_take = take;
            total_dis = tmp_total_dis;
            path = tmp_path;
        } else if (total_dis == tmp_total_dis) {
            if (
                send < min_send ||
                (send == min_send && take < min_take)
            ) {
                min_send = send;
                min_take = take;
                path = tmp_path;
            }
        }
        // backtracking
        tmp_path.pop_back();
        collected[station_no] = 0;
        return ;
    }
    for (int32_t i = 0; i < n + 1; ++i) {
        if (
            stations.edges[station_no][i] != INF && 
            // 路径长度大于的话，直接不用考虑了
            (tmp_total_dis + stations.edges[station_no][i]) <= total_dis &&
            collected[i] != 1
        ) {
            // recording for backtracking
            int32_t tmp_send = send;
            int32_t tmp_take = take;
            int32_t tmp_dis = tmp_total_dis;
            tmp_total_dis += stations.edges[station_no][i];
            if (stations.bikes[i] + take < 0) {
                send += -(stations.bikes[i] + take);
                take = 0;
            } else {
                take += stations.bikes[i];
            }
            dfs_aux(i);
            tmp_total_dis = tmp_dis;
            send = tmp_send;
            take = tmp_take;
        }
    }
    // backtracking
    tmp_path.pop_back();
    collected[station_no] = 0;
}

int main() {
    cin >> count_max >> n >> s_p >> m;
    count_max /= 2;
    stations = Stations (n + 1);
    for (int32_t i = 1; i <= n; ++i) {
        cin >> stations.bikes[i];
        stations.bikes[i] -= count_max;
    }
    for (int32_t i = 0; i < m; ++i) {
        int32_t from, to;
        cin >> from >> to;
        cin >> stations.edges[from][to];
        stations.edges[to][from] = stations.edges[from][to];
    }
    dfs_all();
    // dijkstra_dfs();
}