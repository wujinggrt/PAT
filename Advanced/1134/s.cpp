#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    freopen("i.dat", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    for (int j = 0; j < m; ++j) {
        int from, to;
        cin >> from >> to;
        // j line end side.
        edges[from].push_back(j);
        edges[to].push_back(j);
    }
    int k;
    cin >> k;
    for (; k-- != 0; ) {
        int nv;
        cin >> nv;
        vector<int> edge_incidented(m,  0);
        for (int i = 0; i < nv; ++i) {
            int index;
            cin >> index;
            for (auto other_end: edges[index]) {
                edge_incidented[other_end] = 1;
            }
        }
        cout << (all_of(begin(edge_incidented), end(edge_incidented), [] (int e) { return e == 1; }) ? "Yes" : "No") << endl;
    }
}
