#include <cctype>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

static const string weekday_table[7] = {
    "MON"s,
    "TUE"s,
    "WED"s,
    "THU"s,
    "FRI"s,
    "SAT"s,
    "SUN"s
};

int main() {
    string first;
    string second;
    string third;
    string fourth;
    cin >> first >> second >> third >> fourth;
    int32_t weekday = 0;
    bool weekday_not_found = true;
    int32_t hour = -1;
    auto is_hour = [] (char c) -> bool {
        return isdigit(c) || (c >= 'A' && c <= 'N');
    };
    for (size_t i = 0; i < first.size() && i < second.size(); ++i) {
        if (first[i] == second[i]) {
            if (weekday_not_found && first[i] >= 'A' && first[i] <= 'G') {
                weekday = first[i] - 'A';
                weekday_not_found = false;
            } else if (!weekday_not_found && is_hour(first[i])) {
                hour = (first[i] <= '9' ? first[i] - '0' : first[i] - 'A' + 10);
                break;
            }
        }
    }
    int32_t minute = -1;
    for (size_t i = 0; i < third.size() && i < fourth.size(); ++i) {
        if (third[i] == fourth[i] && isalpha(third[i])) {
            minute = i;
            break;
        }
    }
    printf("%s %02d:%02d\n", weekday_table[weekday].c_str(), hour, minute);
}