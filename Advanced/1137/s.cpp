#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("i.dat", "r", stdin);
    int p, m, n;
    cin >> p >> m >> n;
    unordered_map<string, int> programmings;
    for (; p-- > 0; ) {
        string id;
        int points;
        cin >> id >> points;
        // 合格的才会被记录
        if (points >= 200) {
            programmings[id] = points;
        }
    }
    unordered_map<string, int> mid_scores;
    for (; m-- > 0; ) {
        string id;
        int score;
        cin >> id >> score;
        mid_scores[id] = score;
    }
    unordered_map<string, int> final_scores;
    for (; n-- > 0; ) {
        string id;
        int score;
        cin >> id >> score;
        final_scores[id] = score;
    }
    struct Stu {
        string id;
        int programming;
        int mid_score;
        int final_score;
        int final_grade;
    };
    vector<Stu> qualified;
    for (auto& entry: programmings) {
        auto iter_mid = mid_scores.find(entry.first);
        int mid_score = iter_mid == end(mid_scores) ? -1 : iter_mid->second;
        auto iter_final = final_scores.find(entry.first);
        int final_score = iter_final == end(final_scores) ? -1 : iter_final->second;
        int final_grade = final_score;
        if (mid_score > final_score) {
            double temp_grade = (double) mid_score * 0.4 + (double) final_score * 0.6;
            final_grade = temp_grade + 0.5;
            //if (temp_grade > (int) temp_grade) {
                //final_grade = (int) temp_grade + 1;
            //} else {
                //final_grade = (int) temp_grade;
            //}
        }
        if (final_grade >= 60) {
            qualified.push_back(Stu{entry.first, entry.second, mid_score, final_score, final_grade});
        }
    }
    sort(begin(qualified), end(qualified), [] (const Stu& lhs, const Stu& rhs) {
        if (lhs.final_grade != rhs.final_grade) {
            return lhs.final_grade > rhs.final_grade;
        }
        return lhs.id < rhs.id;
    });
    for (auto& stu: qualified) {
        cout << stu.id << " " << stu.programming << " " << stu.mid_score << " " << stu.final_score << " " << stu.final_grade << "\n";
    }
}
