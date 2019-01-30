#include <iostream>
using namespace std;

struct Student {
    char gender;
    int32_t grade;
    string name;
    string id;
};

int main() {
    int32_t n;
    cin >> n;
    Student male{'M', INT32_MAX, "", ""};
    Student female{'F', -1, "", ""};
    bool has_male = false;
    bool has_female = false;
    for (int32_t i = 0; i < n; ++i) {
        Student tmp;
        cin >> tmp.name >> tmp.gender >> tmp.id >> tmp.grade;
        if (tmp.gender == 'M') {
            if (tmp.grade < male.grade) {
                male = tmp;
                has_male = true;
            }
        } else {
            if (tmp.grade > female.grade) {
                female = tmp;
                has_female = true;
            }
        }
    }
    if (has_male && has_female) {
        cout << female.name << " " << female.id << "\n";
        cout << male.name << " " << male.id << "\n";
        cout << female.grade - male.grade << "\n";
    } else {
        if (!has_female) {
            cout << "Absent\n";
        } else {
            cout << female.name << " " << female.id << "\n";
        }
        if (!has_male) {
            cout << "Absent\n";
        } else {
            cout << male.name << " " << male.id << "\n";
        }
        cout << "NA\n";
    }
}