#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct CallInfo {
    bool visited = false;
    int32_t total;
    map<string, int32_t> others;
};

static const int32_t INF = 0x3F3F3F3F;
int32_t n, k;
vector<vector<int32_t>> call_time;
vector<string> callers;
vector<int32_t> color;
vector<vector<string>> gangs;

void dfs_aux(size_t, vector<string>&);

void dfs() {
    color = vector<int32_t> (call_time.size(), 0);
    for (size_t v = 0; v < call_time.size(); ++v) {
        if (color[v] == 0) {
            gangs.push_back(vector<string>());
            dfs_aux(v, gangs.back());
            if (gangs.back().size() <= 2) {
                gangs.pop_back();
            }
        }
    }
}

void dfs_aux(size_t u, vector<string>& gangs) {
    gangs.push_back(callers[u]);
    color[u] = 1;
    for (size_t v = 0; v < call_time.size(); ++v) {
        if (call_time[u][v] != INF && color[v] == 0) {
            dfs_aux(v, gangs);
        }
    }
    color[u] = 2;
}

int main() {
    cin >> n >> k;
    map<string, CallInfo> calls;
    for (int32_t i = 0; i < n; ++i) {
        string end_a;
        string end_b;
        int32_t time;
        cin >> end_a >> end_b >> time;
        calls[end_a].total += time;
        calls[end_a].others[end_b] += time;;
        calls[end_b].total += time;
        calls[end_b].others[end_a] += time;;
    }
    call_time = vector<vector<int32_t>> (
        calls.size(), 
        vector<int32_t>(calls.size(), INF));
    callers = vector<string> (calls.size());
    vector<int32_t> visited(calls.size(), 0);
    size_t idx = 0;
    map<string, size_t> index;
    for (auto& e: calls) {
        index[e.first] = idx;
        ++idx;
    }
    idx = 0;
    // 建立无向图
    for (auto& e: calls) {
        callers[idx] = e.first;
        // 联系其他人
        for (auto& user: e.second.others) {
            auto to = index[user.first];
            call_time[idx][to] = user.second;
        }
        ++idx;
    }
    dfs();
    for (auto& e: gangs) {
        int32_t relations = 0;
        for (size_t i = 0; i < e.size(); ++i) {
            for (size_t j = i + 1; j < e.size(); ++j) {
                auto iter = calls[e[i]].others.find(e[j]);
                if (iter == end(calls[e[i]].others)) {
                    continue;
                } else {
                    relations += iter->second;
                }
            }
        }
        if (relations <= k) {
            e = vector<string>();
        }
    }
    gangs.erase(remove_if(begin(gangs), end(gangs), [] (auto& e) {
        return e == vector<string>();
    }), end(gangs));
    cout << gangs.size() << "\n";
    vector<pair<string, int32_t>> vec;
    for (auto& e: gangs) {
        auto iter = max_element(begin(e), end(e), [&] (auto& l, auto& r) {
            return calls[l].total < calls[r].total;
        });
        vec.emplace_back(*iter, e.size());
    }
    sort(begin(vec), end(vec), [] (auto& l, auto& r) {
        return l.first < r.first;
    });
    for (auto& e: vec) {
        cout << e.first << " " << e.second << "\n";
    }
}