#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dfs_aux(uint32_t u);

vector<vector<int32_t>> graph;
// 0: White, 1:Gray正在访问中, 2:Black
vector<int32_t> color;
int32_t components = 0;
int32_t max_height = 0;
int32_t tmp_height = 0;
vector<int32_t> nodes;
int32_t n;

// 计算连通分量
void dfs() {
    color = vector<int32_t> (n, 0);
    for (int32_t v = 0; v < color.size(); ++v) {
        if (color[v] == 0) {
            ++components;
            dfs_aux(v);
        }
    }
}

void dfs_aux(uint32_t u) {
    color[u] = 1;
    for (const auto& v: graph[u]) {
        if (color[v] == 0) {
            dfs_aux(v);
        }
    }
    color[u] = 2;
}

void dfs_longest_aux(uint32_t u);

// 0: 代表从这个点出发，作为root，深度小于之前的maax_height
// 1: 代表从这个点出发，作为root，深度大于或等于之前的maax_height，push这个点
bool flag = false;

// 遍历最长路径
void dfs_longest() {
    color = vector<int32_t> (n, 0);
    for (int32_t v = 0; v < color.size(); ++v) {
        tmp_height = 0;
        flag = 0;
        dfs_longest_aux(v);
        if (flag) {
            nodes.push_back(v + 1);
        }
    }
}

void dfs_longest_aux(uint32_t u) {
    color[u] = 1;
    for (const auto& v: graph[u]) {
        if (color[v] == 0) {
            auto tmp = tmp_height;
            ++tmp_height;
            if (tmp_height > max_height) {
                max_height = tmp_height;
                nodes.clear();
                nodes.shrink_to_fit();
                flag = true;
            } else if (tmp_height == max_height) {
                flag = true;
            }
            dfs_longest_aux(v);
            // backtracking
            tmp_height = tmp;
        }
    }
    color[u] = 0;
}

int main() {
    cin >> n;
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    graph = vector<vector<int32_t>> (n);
    for (int32_t i = 0; i < n - 1; ++i) {
        int32_t from;
        int32_t to;
        cin >> from >> to;
        graph[from - 1].push_back(to - 1);
        graph[to - 1].push_back(from - 1);
    }
    dfs();
    if (components > 1) {
        printf("Error: %d components\n", components);
    } else {
        dfs_longest();
        sort(begin(nodes), end(nodes));
        for (auto& e: nodes) {
            cout << e << "\n";
        }
    }
}