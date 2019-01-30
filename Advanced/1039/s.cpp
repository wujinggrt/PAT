#include <set>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int32_t n, k;
    cin >> n >> k;
    unordered_map<string, set<int32_t>> students;
    students.reserve(n);
    for (int32_t i = 0; i < k; ++i) {
        int32_t no, cnt;
        cin >> no >> cnt;
        for (int32_t j = 0; j < cnt; ++j) {
            char c_name[5];
            scanf("%s", c_name);
            string name(c_name);
            // cin >> name;
            students[name].insert(no);
        }
    }
    for (int32_t i = 0; i < n; ++i) {
        char c_name[5];
        scanf("%s", c_name);
        string name(c_name);
        // cin >> name;
        printf("%s ", name.c_str());
        auto iter = students.find(name);
        if (iter == end(students)) {
            printf("0\n");
        } else {
            cout << iter->second.size();
            for (auto& e: iter->second) {
                printf(" %d", e);
            }
            cout << "\n";
        }
    }
}