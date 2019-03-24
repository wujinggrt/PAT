#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

struct Student {
    string name;
    string id;
    int grade;
};

int main() {
    int n;
    cin >> n;
    vector<Student> records(n);
    for (auto& p: records) {
        cin >> p.name >> p.id >> p.grade;
    }
    int grade1, grade2;
    cin >> grade1 >> grade2;
    // 降序
    sort(begin(records), end(records), [] (auto& lhs, auto& rhs) {
        return lhs.grade > rhs.grade;
    });
    bool not_has_stu = true;
    for (auto& p: records) {
        if (p.grade <= grade2 && p.grade >= grade1) {
            not_has_stu = false;
            cout << p.name << " " << p.id << "\n";
        }
    }
    if (not_has_stu) {
        cout << "NONE\n";
    }
    return 0;
    // // 第一个小于grade1的，作为终点
    // auto iter_lower = find_if(begin(records), end(records), [=] (auto& e) {
    //     return e.grade < grade1;
    // });
    // // 第一个小于等于grade2，作为起点
    // auto iter_upper = find_if(begin(records), end(records), [=] (auto& e) {
    //     return e.grade <= grade2;
    // });
    // if (iter_begin == end(records)) { // 全部大于等于grade1
    //     if (iter_upper == end(records)) { // 全部小于等于grade2
    //         for (auto& p: records) {
    //             cout << p.name << " " << p.id << "\n";
    //         }
    //     } else { // 
    //         for (; iter_upper != iter_lower; ++iter_upper) {
    //             cout << iter_uppername << " " << iter_upperid << "\n";
    //         }
    //     }
    // } else {
    //     if (iter_begin == )
    //     cout << "NONE\n";
    //     return 0;
    // }
}