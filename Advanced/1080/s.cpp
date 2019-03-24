#include <cstdio>

#include <deque>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

static const int INF = 0x3f3f3f3f;

struct Student {
    int id;
    int ge;
    int gi;
    int total;
    int rank = -1;
    vector<int> prefer;
    Student(int school_num) : prefer(school_num) {}
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> school(m);
    for (auto& num: school) {
        cin >> num;
    }
    vector<Student> students(n, Student(k));
    for (int id = 0; id < n; ++id) {
        cin >> students[id].ge >> students[id].gi;
        students[id].total = students[id].ge + students[id].gi;
        for (auto& p: students[id].prefer) {
            cin >> p;
        }
        students[id].id = id;
    }
    sort(begin(students), end(students), [] (auto& lhs, auto& rhs) {
        if (lhs.total != rhs.total) {
            return lhs.total > rhs.total;
        } else if (lhs.ge != rhs.ge) {
            return lhs.ge > rhs.ge;
        } else {
            return false;
        }
    });
    int rank = 0;
    // 方便计算排名
    int former_score = INF;
    int former_ge = INF;
    for (int i = 0; i < students.size(); ++i) {
        // 排名不同
        if (former_score > students[i].total ||
            (former_score == students[i].total && former_ge > students[i].ge)) {
            rank = i + 1;
            students[i].rank = rank;
        } else {
            students[i].rank = rank;
        }
        former_score = students[i].total;
        former_ge = students[i].ge;
    }
    // 这是一个学校考虑的学生的队列，判断每次的最后一名是否相等，
    // 就可以知道是否需要超过quota
    vector<deque<Student>> considered(m);
    for (auto& stu: students) {
        for (auto index: stu.prefer) {
            if (school[index] != 0) {
                --school[index];
                considered[index].push_back(stu);
                break;
            } else {
                if (considered[index].back().rank == stu.rank) {
                    considered[index].push_back(stu);
                    break;
                }
            }
        }
    }
    for (auto& consider: considered) {
        bool first = true;
        // 为了方便反向输出
        sort(begin(consider), end(consider), [] (auto& lhs, auto& rhs) { return lhs.id < rhs.id;});
        for (auto& candidate: consider) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << candidate.id;
        }
        cout << "\n";
    }
    // for (auto e: students) {
    //     printf("%d %d %d\n", e.rank, e.total, e.ge);
    // }
}