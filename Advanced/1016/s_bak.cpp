

// 给on-line排序，然后再给off-line排序，
// 然后两个配对
// 即是chronologically

// 唯一的时间
// You may assume that no two records for the same customer have the same time. 
// Times are recorded using a 24-hour clock.

// on-line, off-line等时间记录先按照时间排序，然后从on-line开始，找adjacent的off
// 比如aaa的记录：
// on on off on，则选择第二个on 和第三个off，总之，需要配对
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <functional>
using namespace std;

int main() {
    vector<int32_t> costs(24);
    for (auto &e: costs) {
        cin >> e;
    }
    int32_t n;
    cin >> n;
    map<string, vector<pair<string, string>>, std::less<string>> records;
    vector<string> names;
    names.reserve(n);
    for (int32_t i = 0; i < n; ++i) {
        string name;
        string call_time;
        string on;
        cin >> name;
        cin >> call_time;
        cin >> on;
        // call_time.erase(remove(begin(call_time), end(call_time), ':'), end(call_time));
        records[name].emplace_back(call_time, on);
    }
    for (auto& e: records) {
        sort(begin(e.second), end(e.second));
    }
    vector<pair<string, string>> call_intervals;
    for (auto& e: records) {
        cout << e.first  << " " << string(begin(e.second[0].first), begin(e.second[0].first) + 2) << "\n";
        auto total_amount = 0.;
        for (auto it = begin(e.second); ; ) {
            it = adjacent_find(it, end(e.second), [] (auto& l, auto& r) {
                return (l.second == "on-line"s) && 
                       (r.second == "off-line"s) &&
                       (l.first != r.second);
            });
            if (distance(it, end(e.second)) >= 2) {
                auto it_date_former = begin(it->first) + 3;
                string day_former{it_date_former, it_date_former + 2};
                advance(it_date_former, 3);
                string hour_former{it_date_former, it_date_former + 2};
                advance(it_date_former, 3);
                string minute_former{it_date_former, it_date_former + 2};

                auto it_date_latter = begin((it + 1)->first) + 3;
                string day_latter{it_date_latter, it_date_latter + 2};
                advance(it_date_latter, 3);
                string hour_latter{it_date_latter, it_date_latter + 2};
                advance(it_date_latter, 3);
                string minute_latter{it_date_latter, it_date_latter + 2};

                auto cur_day = stoi(day_former);
                auto cur_hour = stoi(hour_former);
                auto cur_minute = stoi(minute_former);
                auto days = stoi(day_latter) - cur_day;
                auto hours = stoi(hour_latter) - cur_hour;
                auto minutes = days * 24 * 60 + hours * 60 + stoi(minute_latter) - cur_minute;

                cout << string{begin(it->first) + 3, end(it->first)} << " " 
                     << string{begin((it + 1)->first) + 3, end((it + 1)->first)} << " " 
                     << minutes;

                auto prices = 0.;
                for (auto minute_past = minutes; ; ) {
                    auto to_next_minute = 60 - cur_minute;
                    if (minute_past <= to_next_minute) {
                        prices += costs[cur_hour] * minute_past;
                        break;
                    } else {
                        prices += costs[cur_hour] * to_next_minute;
                        cur_minute = 0;
                        ++cur_hour;
                        cur_hour %= 24;
                        minute_past -= to_next_minute;
                    }
                }
                prices /= 100;
                printf(" $%.2f\n", prices);
                total_amount += prices;

                advance(it, 2);
            } else {
                break;
            }
        }
        printf("Total amount: $%.2f\n", total_amount);
    }
}