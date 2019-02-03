#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int32_t n;
    int32_t k;
    scanf("%d %d", &n, &k);
    // unordered_map<int32_t, set<string>> courses;
    unordered_map<int32_t, vector<string>> courses;
    courses.reserve(k);
    for (int32_t i = 0; i < n; ++i) {
        int32_t c;
        char c_name[5];
        scanf("%s %d", c_name, &c);
        string name(c_name);
        for (int32_t j = 0; j < c; ++j) {
            int32_t course_no;
            scanf("%d", &course_no);
            courses[course_no].push_back(name);
        }
    }
    for (int32_t i = 1; i <= k; ++i) {
        auto iter = courses.find(i);
        printf("%d ", i);
        if (iter == end(courses)) {
            printf("0\n");
            continue;
        }
        printf("%zu\n", iter->second.size());
        sort(begin(iter->second), end(iter->second));
        for (const auto& student: iter->second) {
            printf("%s\n", student.c_str());
        }
    }
}