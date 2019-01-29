#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct Student {
    string id;
    string name;
    string grade;
};

int main() {
    int32_t n, c;
    cin >> n >> c;
    vector<Student> records(n);
    for (auto& e: records) {
        cin >> e.id >> e.name >> e.grade;
    }
    if (c == 1) {
        sort(begin(records), end(records), [] (auto& l, auto& r) {
            return l.id < r.id;
        });
    } else if (c == 2) {
        sort(begin(records), end(records), [] (auto& l, auto& r) {
            if (l.name == r.name) {
                return l.id < r.id;
            }
            return l.name < r.name;
        });
    } else {
        sort(begin(records), end(records), [] (auto& l, auto& r) {
            if (l.grade == r.grade) {
                return l.id < r.id;
            }
            return l.grade < r.grade;
        });
    }
    for (auto& e: records) {
        cout << e.id << " " << e.name << " " << e.grade << "\n";
    }
}