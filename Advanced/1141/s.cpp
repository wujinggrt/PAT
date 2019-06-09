#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    freopen("i.dat", "r", stdin);
    int n;
    cin >> n;
    unordered_map<string, vector<double>> scores;
    for (; n-- > 0; ) {
        string id, school;
        double score;
        cin >> id >> score >> school;
        if (id.front() == 'T') {
            score *= 1.5;
        } else if (id.front() == 'B') {
            score /= 1.5;
        }
        for (auto& c: school) {
            c = tolower(c);
        }
        scores[school].push_back(score);
    }
    cout << scores.size() << endl;
    struct Node {
        string id;
        int total_score;
        int num_student;
    };
    vector<Node> rank;
    rank.reserve(scores.size());
    for (const auto& entry: scores) {
        int total_score = accumulate(begin(entry.second), end(entry.second), 0.);
        rank.push_back(Node{entry.first, total_score, (int)entry.second.size()});
    }
    sort(begin(rank), end(rank), [] (const Node& lhs, const Node& rhs) {
        return lhs.total_score != rhs.total_score ?
                    lhs.total_score > rhs.total_score :
                    lhs.num_student != rhs.num_student ?
                        lhs.num_student < rhs.num_student :
                        lhs.id < rhs.id;
    });
    int cur_rank = 0;
    int previous_score = INT32_MAX;
    for (int i = 1; i <= rank.size(); ++i) {
        if (rank[i - 1].total_score != previous_score) {
            cur_rank = i;
        }
        cout << cur_rank << " " << rank[i - 1].id << " " << rank[i - 1].total_score << " " << rank[i - 1].num_student << "\n";
        previous_score = rank[i - 1].total_score;
    }
}
