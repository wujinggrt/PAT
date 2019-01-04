/*

先满足最短路径
需要同时兼顾到路径的长度/权，
还有所经过的每个city的rescue team

*/

#include <vector>
#include <iostream>
#include <string>
using namespace std;

const int INF = 0x3f3f3f3f;

int n;
int m;
int c1;
int c2;

vector<int> dist;
vector<int> paths;

vector<int> collected;
vector<int> path_count;
vector<int> rescue_mates;


struct MGraph {
    vector<vector<int>> arcs;
    vector<int> vertices;
    int vex_num;
    int arc_num;
};

void dikstra(const MGraph& graph) {
    // 下为 Dijkstra
    dist = vector<int>(n, INF);
    // paths里面的值表示如果要过这个顶点，需要经过的点
    paths = vector<int>(n, -1);
    // -1 为没有完成，或者是起始点
    collected = vector<int>(n, 0);
    path_count = vector<int>(n, 0);
    rescue_mates = vector<int>(n, 0);
    dist[c1] = 0;
    rescue_mates[c1] = graph.vertices[c1];
    path_count[c1] = 1;
    for (int i = 0; i < dist.size(); ++i) {
        int min_dist = INF;
        int u = -1;
        // find the least one
        for (int v = 0; v < dist.size(); ++v) {
            if (collected[v] != 1 && dist[v] <= min_dist) {
                min_dist = dist[v];
                u = v;
            }
        }
        collected[u] = 1;
        // for each vertex connected to v
        for (int v = 0; v < graph.vex_num; ++v) {
            if (
                // graph.arcs[u][v] != INF && /* 连通条件 */
                collected[v] != 1 && 
                (graph.arcs[u][v] + dist[u] < dist[v])
            ) {
                dist[v] = graph.arcs[u][v] + dist[u];
                paths[v] = u;
                rescue_mates[v] = rescue_mates[u] + graph.vertices[v];
                path_count[v] = path_count[u];
            } else if (
                collected[v] != 1 && 
                (graph.arcs[u][v] + dist[u] == dist[v])
            ) {
                path_count[v] += path_count[u];
                if (rescue_mates[v] < rescue_mates[u] + graph.vertices[v]) {
                    rescue_mates[v] = rescue_mates[u] + graph.vertices[v];
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> c1 >> c2;
    MGraph graph{
        vector<vector<int>>(n, vector<int>(n, INF)),
        vector<int>(n),
        n,
        m
    };
    for (int i = 0; i < n; ++i) {
        cin >> graph.vertices[i];
    }
    for (int i = 0; i < m; ++i) {
        int from;
        int to;
        cin >> from >> to;
        cin >> graph.arcs[from][to];
        graph.arcs[to][from] = graph.arcs[from][to];
    }
    dikstra(graph);
    cout << path_count[c2] << " " << rescue_mates[c2];
}