#include <unordered_set>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, INF));
    for (int i = 0; i < m; ++i) {
        int city1, city2, dist;
        cin >> city1 >> city2 >> dist;
        --city1;
        --city2;
        graph[city1][city2] = graph[city2][city1] = dist;
    }
    int k;
    cin >> k;
    int min_dist = INF;
    int min_index = -1;
    for (int i = 0; i < k; ++i) {
        int num;
        cin >> num;
        unordered_set<int> visited_cities;
        vector<int> order(num);
        for (auto& item: order) {
            cin >> item;
            --item;
            visited_cities.insert(item);
        }
        bool path_no_exist = false;
        int cur_dist = 0;
        for (int j = 0; j < (int)order.size() - 1; ++j) {
            int from = order[j];
            int to = order[j + 1];
            if (graph[from][to] == INF) {
                path_no_exist = true;
                break;
            }
            cur_dist += graph[from][to];
        }
        if (path_no_exist) {
            printf("Path %d: NA (Not a TS cycle)\n", i + 1);
            // 没有 cycle 就不更新 min_dist|min_index
            continue;
        } else if (order.front() != order.back() || visited_cities.size() != n) {
            printf("Path %d: %d (Not a TS cycle)\n", i + 1, cur_dist);
            // 没有 cycle 就不更新 min_dist|min_index
            continue;
        } else if (num == n + 1) {
            printf("Path %d: %d (TS simple cycle)\n", i + 1, cur_dist);
        } else {
            printf("Path %d: %d (TS cycle)\n", i + 1, cur_dist);
        }
        if (!path_no_exist && cur_dist < min_dist) {
            min_dist = cur_dist;
            min_index = i + 1;
        }
    }
    cout << "Shortest Dist(" << min_index << ") = " << min_dist;
}