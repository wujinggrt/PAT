#include <functional>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

static const int INF = 0x3f3f3f3f;

struct Edge {
    int len = INF;
    int time = INF;
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n, vector<Edge>(n));
    for (int i = 0; i < m; ++i) {
        int v1, v2, one_way, len, t;
        cin >> v1 >> v2 >> one_way >> len >> t;
        graph[v1][v2] = Edge{len, t};
        if (one_way == 0) {
            graph[v2][v1] = Edge{len, t};
        }
    }
    int src, dst;
    cin >> src >> dst;
    
    // dij
    vector<int> visited_dis(n, 0);
    vector<int> visited_time(n, 0);
    vector<vector<int>> parent_dis(n);
    vector<vector<int>> parent_time(n);
    vector<int> dis(n, INF);
    vector<int> time_cost(n, INF);
    dis[src] = 0;
    time_cost[src] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, mindis = INF;
        int u_time = -1, mintime = INF;
        for (int v = 0; v < n; ++v) {
            if (visited_dis[v] == 0 && dis[v] < mindis) {
                mindis = dis[v];
                u = v;
            }
            if (visited_time[v] == 0 && time_cost[v] < mintime) {
                mintime = time_cost[v];
                u_time = v;
            }
        }
        if (u == -1 || u_time == -1) {
            break;
        }
        visited_dis[u] = 1;
        visited_time[u_time] = 1;
        for (int v = 0; v < n; ++v) {
            if (visited_dis[v] == 0) {
                if (dis[v] > dis[u] + graph[u][v].len) {
                    parent_dis[v].clear();
                    parent_dis[v].push_back(u);
                    dis[v] = dis[u] + graph[u][v].len;
                } else if (dis[v] == dis[u] + graph[u][v].len) {
                    parent_dis[v].push_back(u);
                }
            }
            if (visited_time[v] == 0) {
                if (time_cost[v] > time_cost[u_time] + graph[u_time][v].time) {
                    parent_time[v].clear();
                    parent_time[v].push_back(u_time);
                    time_cost[v] = time_cost[u_time] + graph[u_time][v].time;
                } else if (time_cost[v] == time_cost[u_time] + graph[u_time][v].time) {
                    parent_time[v].push_back(u_time);
                }
            }
        }
    }
    vector<int> dis_path;
    vector<int> tmp_path;
    int min_time = INF;
    function<void(int)> dfs_dis = [&] (int index) {
        tmp_path.push_back(index);
        if (index == src) {
            if (dis_path.empty()) {
                dis_path = tmp_path;
                int tmp_time = 0;
                for (int i = tmp_path.size() - 1; i > 0 ; --i) {
                    tmp_time += graph[tmp_path[i]][tmp_path[i - 1]].time;
                }
                min_time = tmp_time;
            } else {
                int tmp_time = 0;
                for (int i = tmp_path.size() - 1; i > 0 ; --i) {
                    tmp_time += graph[tmp_path[i]][tmp_path[i - 1]].time;
                }
                if (tmp_time < min_time) {
                    dis_path = tmp_path;
                }
            }
            tmp_path.pop_back();
            return ;
        }
        for (auto e: parent_dis[index]) {
            dfs_dis(e);
        }
        tmp_path.pop_back();
    };
    dfs_dis(dst);
    vector<int> time_path;
    tmp_path.clear();
    function<void(int)> dfs_time = [&] (int index) {
        tmp_path.push_back(index);
        if (index == src) {
            if (time_path.empty()) {
                time_path = tmp_path;
            } else {
                if (tmp_path.size() < time_path.size()) {
                    time_path = tmp_path;
                }
            }
            tmp_path.pop_back();
            return ;
        }
        for (auto e: parent_time[index]) {
            dfs_time(e);
        }
        tmp_path.pop_back();
    };
    dfs_time(dst);
    if (dis_path != time_path) {
        printf("Distance = %d: ", dis[dst]);
        bool first = true;
        for (auto iter = crbegin(dis_path); iter != crend(dis_path); ++iter) {
            if (first) {
                first = false;
            } else {
                cout << " -> ";
            }
            cout << *iter;
        }
        cout << "\n";
        printf("Time = %d: ", time_cost[dst]);
        first = true;
        for (auto iter = crbegin(time_path); iter != crend(time_path); ++iter) {
            if (first) {
                first = false;
            } else {
                cout << " -> ";
            }
            cout << *iter;
        }
        cout << "\n";
    } else {
        printf("Distance = %d; Time = %d: ", dis[dst], time_cost[dst]);
        bool first = true;
        for (auto iter = crbegin(dis_path); iter != crend(dis_path); ++iter) {
            if (first) {
                first = false;
            } else {
                cout << " -> ";
            }
            cout << *iter;
        }
        cout << "\n";
    }
}