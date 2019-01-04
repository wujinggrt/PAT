#include <utility>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

struct QuestionItem {
    int score;
    int selection_count;
    int correct_count;
    unordered_map<char, bool> answers;
};

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<QuestionItem> vec(m);
    for (int i = 0; i < m; ++i) {
        cin >> vec[i].score
            >> vec[i].selection_count
            >> vec[i].correct_count;
        for (int j = 0; j < vec[i].correct_count; ++j) {
            char answer;
            cin >> answer;
            vec[i].answers[answer] = 1;
        }
    }
    vector<int> wrong_record(m);
    int max_wrong_count = 0;
    for (int i = 0; i < n; ++i) {
        int score = 0;
        for (int j = 0; j < m; ++j) {
            int correct_flag = true;
            int count;
            // 读取最后的换行符
            char c;
            cin >> c;
            cin >> count;
            if (count != vec[j].correct_count) {
                correct_flag = false;
            }
            char choice;
            for (int k = 0; k < count; ++k) {
                cin >> choice;
                if (vec[j].answers[choice] != 1) {
                    correct_flag = false;
                }
            }
            cin >> c;
            if (correct_flag) {
                score += vec[j].score;
            } else {
                ++wrong_record[j];
                if (wrong_record[j] > max_wrong_count) {
                    max_wrong_count = wrong_record[j];
                }
            }
        }
        cout << score << '\n';
    }
    if (max_wrong_count == 0) {
        cout << "Too simple\n";
    } else {
        cout << max_wrong_count;
        for (int i = 0; i < wrong_record.size(); ++i) {
            if (wrong_record[i] == max_wrong_count) {
                cout << " " << (i + 1);
            }
        }
        cout << '\n';
    }
    return 0;
}