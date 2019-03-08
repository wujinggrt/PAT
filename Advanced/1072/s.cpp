#include <cstdio>

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

static const int INF = 0x3f3f3f3f;

int main() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    // 前面n个为hourses,最后m个最为gas station candidate
    vector<vector<int>> graph(n + m, vector<int>(n + m, INF));
    for (int i = 0; i < k; ++i) {
        string from;
        string to;
        int dist;
        cin >> from >> to >> dist;
        int fromPos;
        int toPos;
        if (from.front() != 'G') {
            fromPos = stoi(from) - 1;
        } else {
            fromPos = stoi(from.substr(1)) + n - 1;
        }
        if (to.front() != 'G') {
            toPos = stoi(to) - 1;
        } else {
            toPos = stoi(to.substr(1)) + n - 1;
        }
        graph[fromPos][toPos] = dist;
        graph[toPos][fromPos] = dist;
    }
    vector<int> visited(n + m, 0);
    vector<int> dis(n + m, INF);
    int bestStation = -1;
    double bestDis = -1;
    double bestAverage = -1;
    // traverse the gas candidate
    for (int gasStation = n; gasStation < n + m; gasStation++) {
        double minDis = INF;
        double average = 0;
        // reset the state
        fill(begin(dis), end(dis), INF);
        fill(begin(visited), end(visited), 0);
        // 从gasStation开始
        dis[gasStation] = 0;
        // dijkstra
        for (int i = 0; i < n + m; i++) {
            int u = -1;
            int minNum = INF;
            for (int j = 0; j < n + m; j++) {
                if (visited[j] == 0 && dis[j] < minNum) {
                    u = j;
                    minNum = dis[j];
                }
            }
            if (u == -1) {
                break;
            }
            visited[u] = 1;
            for (int v = 0; v < n + m; v++) {
                if (visited[v] == 0 && dis[v] > dis[u] + graph[u][v]) {
                    dis[v] = dis[u] + graph[u][v];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            // gas station不能够服务了
            if (dis[i] > d) {
                minDis = -1;
                break;
            }
            if (dis[i] < minDis) {
                minDis = dis[i];
            }
            average += static_cast<double>(dis[i]);
        }
        // 不能够服务，只能找下一个
        if (minDis == -1) {
            continue;
        }
        average /= static_cast<double>(n);
        if (minDis > bestDis) {
            bestStation = gasStation;
            bestDis = minDis;
            bestAverage = average;
        } else if (minDis == bestDis && average < bestAverage) { // 相等的case
            bestStation = gasStation;
            bestAverage = average;
        }
    }
    if (bestStation == -1) {
        printf("No Solution\n");
    } else {
        printf("G%d\n%.1f %.1f\n", bestStation - n + 1, bestDis, bestAverage);
    }
}