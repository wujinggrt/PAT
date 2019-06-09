#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <functional>
using namespace std;

#define PRINT_LINE cout << __LINE__ << endl;

int main() {
    //freopen("i.dat", "r", stdin);
    int n;
    cin >> n;
    unordered_map<int, unordered_map<int, int>> line_id;
    unordered_map<int, vector<int>> next_station;
    unordered_map<int, bool> visited;
    for (int i = 1; i <= n; ++i) {
        int m;
        int pre;
        cin >> m >> pre;
        visited[pre] = false;
        for (int j = 0; j < m - 1; ++j) {
            int cur;
            cin >> cur;
            line_id[pre][cur] = i;
            line_id[cur][pre] = i;
            next_station[pre].push_back(cur);
            next_station[cur].push_back(pre);
            visited[cur] = false;
            pre = cur;
        }
    }
    int k;
    cin >> k;
    function<int(const vector<int>&)> num_transfer = [&] (const vector<int>& path) {
        int num_change = 0;
        int pre = path.front();
        for (int i = 1; i < path.size() - 1; ++i) {
            int cur = path[i];
            int next = path[i + 1];
            if (line_id[pre][cur] != line_id[cur][next]) {
                ++num_change;
            }
            pre = cur;
        }
        return num_change;
    };
    vector<int> min_path;
    vector<int> tmp_path;
    int dst = 0;
    const int INF = 0x3f3f3f3f;
    int min_transfer = INF;
    int min_distance = INF;
    function<void(int)> dfs = [&] (int from) {
        visited[from] = true;
        tmp_path.push_back(from);
        if (from == dst) {
            auto num_cur_change = num_transfer(tmp_path);
            if (tmp_path.size() - 1 < min_distance) {
                min_distance = tmp_path.size() - 1;
                min_path = tmp_path;
                min_transfer = num_cur_change;
            } else if (tmp_path.size() - 1 == min_distance && num_cur_change < min_transfer) {
                min_path = tmp_path;
                min_transfer = num_cur_change;
            }
            return;
        }
        for (auto next: next_station[from]) {
            if (!visited[next]) {
                dfs(next);
                tmp_path.pop_back();
                visited[next] = false;
            }
        }
    };
    function<void()> print_path = [&] () {
        int start = min_path.front();
        if (min_transfer == 0) {
            printf("Take Line#%d from %04d to %04d.\n", line_id[start][min_path[1]], start, min_path.back());
            return ;
        }
        int pre = start;
        for (int i = 1; i < min_path.size() - 1; ++i) {
            int cur = min_path[i];
            int next = min_path[i + 1];
            // 换了
            if (line_id[pre][cur] != line_id[cur][next]) {
                printf("Take Line#%d from %04d to %04d.\n", line_id[pre][cur], start, cur);
                start = cur;
            }
            pre = cur;
        }
        // The last change
        printf("Take Line#%d from %04d to %04d.\n", line_id[*(end(min_path) - 1)][*(end(min_path) - 2)], start, min_path.back());
    };
    for (; k > 0; --k) {
        for (auto& entry: visited) {
            entry.second = false;
        }
        min_path.clear();
        tmp_path.clear();
        min_distance = INF;
        min_transfer = INF;
        int from;
        cin >> from >> dst;
        dfs(from);
        cout << min_distance << endl;
        print_path();
    }
}
