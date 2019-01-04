#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> scores(n);
    vector<int> ans(n);
    for (int i = 0; i < m; ++i) {
        cin >> scores[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> ans[i];
    }
    for (int i = 0; i < n; ++i) {
        int score = 0;
        for (int j = 0; j < m; ++j) {
            int a = 0;
            cin >> a;
            if (a == ans[j]) {
                score += scores[j];
            }
        }
        cout << score << '\n';
    }
    return 0;
}