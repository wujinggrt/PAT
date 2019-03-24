#include <functional>
#include <unordered_map>
#include <string>
#include <vector>
#include <utility>
#include <cstdio>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Node {
    string name;
    int happiness;
    /**
     * arcs.first idx
     * arcs.second distance
     * */
    vector<pair<int, int>> arcs;
};

void ListDij() {
    int n, k;
    string start;
    cin >> n >> k >> start;
    vector<Node> graph(n);
    unordered_map<string, int> city_idx;
    graph.front().name = start;
    graph.front().happiness = 0;
    city_idx[start] = 0;
    for (int i = 1; i < graph.size(); ++i) {
        cin >> graph[i].name >> graph[i].happiness;
        // 记录城市下标
        city_idx[graph[i].name] = i;
    }
    for (int i = 0; i < k; ++i) {
        string from, to;
        int cost;
        cin >> from >> to >> cost;
        int from_idx = city_idx[from];
        int to_idx = city_idx[to];
        graph[from_idx].arcs.emplace_back(to_idx, cost);
        graph[to_idx].arcs.emplace_back(from_idx, cost);
    }
    int dest = city_idx["ROM"];
    vector<int> visited(graph.size(), 0); // visited
    vector<int> dist(graph.size(), INF); // 距离出发点最短dist
    vector<vector<int>> parent(graph.size());
    dist[0] = 0;
    for (int i = 0; i < graph.size(); ++i) {
        int u = -1;
        int min_dist = INF;
        for (int v = 0; v < dist.size(); ++v) {
            if (!visited[v] && dist[v] < min_dist) {
                u = v;
                min_dist = dist[v];
            }
        }
        if (u == -1) {
            printf("%d u == -1\n", i);
            continue;
        }
        visited[u] = 1;
        for (int v = 0; v < graph[u].arcs.size(); ++v) {
            auto to_idx = graph[u].arcs[v].first;
            auto to_cost = graph[u].arcs[v].second;
            if (!visited[to_idx]) {
                if (dist[to_idx] > dist[u] + to_cost) {
                    dist[to_idx] = dist[u] + to_cost;
                    parent[to_idx].clear();
                    parent[to_idx].push_back(u);
                } else if (dist[to_idx] == dist[u] + to_cost) {
                    parent[to_idx].push_back(u);
                }
            }
        }
    }
    cout << dist[dest] << "\n";
}

struct City {
    string name;
    int happiness;
};

void MatDij() {
    int n, k;
    string start;
    cin >> n >> k >> start;
    vector<vector<int>> graph(n, vector<int>(n, INF));
    unordered_map<string, int> city_idx;
    vector<City> cities(n);
    cities[0] = City{start, 0};
    city_idx[start] = 0;
    graph[0][0] = INF;
    for (int i = 1; i < cities.size(); ++i) {
        cin >> cities[i].name >> cities[i].happiness;
        city_idx[cities[i].name] = i;
    }
    for (int i = 0; i < k; ++i) {
        string from, to;
        int cost;
        cin >> from >> to >> cost;
        int from_idx = city_idx[from];
        int to_idx = city_idx[to];
        graph[from_idx][to_idx] = cost;
        graph[to_idx][from_idx] = cost;
    }
    int dest = city_idx["ROM"];
    vector<int> visited(graph.size(), 0); // visited
    vector<int> dist(graph.size(), INF); // 距离出发点最短dist
    vector<vector<int>> parent(graph.size());
    dist[0] = 0;
    for (int i = 0; i < graph.size(); ++i) {
        int u = -1;
        int min_dist = INF;
        for (int v = 0; v < dist.size(); ++v) {
            if (!visited[v] && dist[v] < min_dist) {
                u = v;
                min_dist = dist[v];
            }
        }
        visited[u] = 1;
        for (int v = 0; v < graph[u].size(); ++v) {
            if (!visited[v]) {
                if (dist[v] > dist[u] + graph[u][v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v].clear();
                    parent[v].push_back(u);
                } else if (dist[v] == dist[u] + graph[u][v]) {
                    parent[v].push_back(u);
                }
            }
        }
    }
    int num_different = 0;
    int max_happiness = 0;
    vector<int> path;
    vector<int> tmp_path;
    function<void(int)> dfs = [&] (int idx) {
        tmp_path.push_back(idx);
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
        tmp_path.pop_back();
    };
    dfs(dest);
    printf("%d %d %d %lu\n", num_different, dist[dest], max_happiness, max_happiness / (path.size() - 1));
    for (auto iter = rbegin(path); iter != rend(path); ++iter) {
        cout << cities[*iter].name << (iter == rend(path) - 1 ? "" : "->");
    }
    cout << "\n";
}

int main() {
    MatDij();
}