#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> m;
    int max_no = 0;
    int max_score = 0;
    for (int i = 0; i < n; ++i) {
        int no;
        int player;
        int score;
        scanf("%d-%d %d", &no, &player, &score);
        int temp_score = m[no];
        auto it = m.find(no);
        if (it == m.end()) {
            m[no] = score;
            temp_score = score;
        } else {
            it->second += score;
            temp_score = it->second;
        }
        if (temp_score > max_score) {
            max_no= no;
            max_score = temp_score;
        }
    }
    cout << max_no << " " << max_score << '\n';
    return 0;
}