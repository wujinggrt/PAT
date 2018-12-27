#include <string>
#include <cstdio>
#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, pair<string, int>> student_data;
    for (int i = 0; i < n; ++i) {
        int t;
        string temp;
        int e;
        cin >> temp >> t >> e;
        student_data[t] = make_pair(temp, e);
    }
    int m;
    cin >> m;
    int testing_no;
    while (cin >> testing_no) {
        auto it = student_data.find(testing_no);
        printf("%s %d\n", it->second.first.c_str(), it->second.second);
    }
    return 0;
}