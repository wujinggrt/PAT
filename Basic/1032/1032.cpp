#include <algorithm>
#include <iostream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <map>
#include <utility>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i)
    {
        int id;
        int score;
        cin >> id >> score;
        m[id] += score;
    }
    vector<pair<int, int>> vec;
    vec.reserve(m.size());
    for (auto &e: m)
    {
        vec.push_back(std::move(e));
    }
    sort(vec.begin(), vec.end(), [] (const auto &l, const auto &r) {
        return l.second > r.second;
    });
    printf("%d %d\n", vec.begin()->first, vec.begin()->second);
    return 0;
}