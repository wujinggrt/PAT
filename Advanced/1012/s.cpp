#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Student {
    string id;
    int c;
    int m;
    int e;
    int a;
};

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<Student> reports(n);
    for (int i = 0; i < n; ++i) {
        cin >> reports[i].id >> reports[i].c >> reports[i].m >> reports[i].e;
        reports[i].a = (reports[i].c + reports[i].m + reports[i].e) / 3;
    }
    unordered_map<string, vector<pair<int, string>>> ranking;
    sort(reports.begin(), reports.end(), [] (const auto &l, const auto &r) {
        return l.a > r.a;
    });
    for (int i = 0, rank_tmp = 1; i < n; ++i) {
        // 相等的分数，排名相同，如 1 2 2 4，在4的时候，就是i+1，如果相同，如2，则不更新rank_tmp
        if (i != 0 && reports[i].a != reports[i - 1].a) {
            rank_tmp = i + 1;
        }
        ranking[reports[i].id] = vector<pair<int, string>>{make_pair(rank_tmp, "A")};
    }
    sort(reports.begin(), reports.end(), [] (const auto &l, const auto &r) {
        return l.c > r.c;
    });
    for (int i = 0, rank_tmp = 1; i < n; ++i) {
        // 相等的分数，排名相同
        if (i != 0 && reports[i].c != reports[i - 1].c) {
            rank_tmp = i + 1;
        }
        auto it = ranking.find(reports[i].id);
        it->second.emplace_back(rank_tmp, "C");
    }
    sort(reports.begin(), reports.end(), [] (const auto &l, const auto &r) {
        return l.m > r.m;
    });
    for (int i = 0, rank_tmp = 1; i < n; ++i) {
        // 相等的分数，排名相同
        if (i != 0 && reports[i].m != reports[i - 1].m) {
            rank_tmp = i + 1;
        }
        auto it = ranking.find(reports[i].id);
        it->second.emplace_back(rank_tmp, "M");
    }
    sort(reports.begin(), reports.end(), [] (const auto &l, const auto &r) {
        return l.e > r.e;
    });
    for (int i = 0, rank_tmp = 1; i < n; ++i) {
        // 相等的分数，排名相同
        if (i != 0 && reports[i].e != reports[i - 1].e) {
            rank_tmp = i + 1;
        }
        auto it = ranking.find(reports[i].id);
        it->second.emplace_back(rank_tmp, "E");
    }
    for (int i = 0; i < m; ++i) {
        string checking;
        cin >> checking;
        auto it = ranking.find(checking);
        if (it != ranking.end()) {
            auto m = min_element(it->second.begin(), it->second.end(), [] (const auto &l, const auto &r) {
                return l.first < r.first;
            });
            printf("%d %s\n", m->first, m->second.c_str());
        } else {
            printf("N/A\n");
        }
    }
}