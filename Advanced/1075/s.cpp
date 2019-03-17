#include <cstdio>

#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Student {
    string id;
    int total;
    int perfectSolve;
    bool neverPassed;
    vector<int> scores;
    vector<int> submittedFlags;
};

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> problem(k);
    for (auto& item: problem) {
        cin >> item;
    }
    unordered_map<string, Student> submitted;
    for (int i = 0; i < m; ++i) {
        string id;
        cin >> id;
        auto iter = submitted.find(id);
        if (iter == cend(submitted)) {
            // for -2 < -1
            submitted.insert({id, Student{id, 0, 0, true, vector<int>(k, 0), vector<int>(k, 0)}});
        }
        int no, score;
        cin >> no >> score;
        iter = submitted.find(id);
        // 代表他提交过了
        iter->second.submittedFlags[no - 1] = 1;
        // 只有得分更高的才可以更新
        if (iter->second.scores[no - 1] < score) {
            iter->second.total += score - iter->second.scores[no - 1];
            iter->second.scores[no - 1] = score;
        }
        // For those who has never submitted any solution that **can pass** the compiler, 
        // or has **never submitted** any solution, 
        // they must NOT be shown on the ranklist. 
        // 有编译成功的item
        if (score != -1) {
            iter->second.neverPassed = false;
        }
    }
    vector<Student> students;
    for (auto& entry: submitted) {
        for (int i = 0; i < entry.second.scores.size(); ++i) {
            if (entry.second.scores[i] == problem[i]) {
                entry.second.perfectSolve++;
            }
        }
        students.push_back(entry.second);
    }
    sort(begin(students), end(students), [] (auto& lhs, auto& rhs) {
        if (lhs.total != rhs.total) {
            return lhs.total > rhs.total;
        } else if (lhs.perfectSolve != rhs.perfectSolve) {
            return lhs.perfectSolve > rhs.perfectSolve;
        } else {
            return lhs.id < rhs.id;
        }
    });
    int rank = 0;
    // 不用计数器的话，跳过了某一个student
    int numPassed = 0;
    int formerTotal = INT32_MIN;
    for (int i = 0; i < students.size(); ++i) {
        // 没有通过的不能够print 
        if (students[i].neverPassed) {
            continue;
        }
        ++numPassed;
        if (formerTotal != students[i].total) {
            rank = numPassed;
            formerTotal = students[i].total;
        }
        printf("%d %s %d ", rank, students[i].id.c_str(), students[i].total);
        bool first = true;
        for (int j = 0; j < students[i].scores.size(); ++j) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << (students[i].submittedFlags[j] == 1 ? to_string(students[i].scores[j]) :  "-"s);
        }
        cout << "\n";
    }
}