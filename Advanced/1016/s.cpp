#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <functional>
using namespace std;

struct CallDate {
    string date;
    string state;
};

struct CallRecord {
    string time;
    double costs;
};

struct Result {
    string name_and_month;
    vector<CallRecord> call_data;
    double total_amount;
};

int main() {
    vector<int32_t> costs(24);
    for (auto &e: costs) {
        cin >> e;
    }
    int32_t n;
    cin >> n;
    map<string, vector<CallDate>, std::less<string>> records;
    vector<string> names;
    names.reserve(n);
    for (int32_t i = 0; i < n; ++i) {
        string name;
        string call_time;
        string on;
        cin >> name;
        cin >> call_time;
        cin >> on;
        records[name].push_back(CallDate{call_time, on});
    }
    for (auto& e: records) {
        sort(begin(e.second), end(e.second), [] (auto& l, auto& r) {
            return l.date < r.date;
        });
    }
    vector<Result> bills;
    for (auto& e: records) {
        Result result;
        result.name_and_month = e.first + " " + string(begin(e.second[0].date), begin(e.second[0].date) + 2);
        auto total_amount = 0.;
        for (auto it = begin(e.second); ; ) {
            it = adjacent_find(it, end(e.second), [] (auto& l, auto& r) {
                return (l.state == "on-line"s) && 
                       (r.state == "off-line"s);
            });
            if (distance(it, end(e.second)) >= 2) {
                auto it_date_former = begin(it->date) + 3;
                string day_former{it_date_former, it_date_former + 2};
                advance(it_date_former, 3);
                string hour_former{it_date_former, it_date_former + 2};
                advance(it_date_former, 3);
                string minute_former{it_date_former, it_date_former + 2};

                auto it_date_latter = begin((it + 1)->date) + 3;
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
                total_amount += prices;
                result.call_data.push_back(
                    CallRecord {
                        string{begin(it->date) + 3, end(it->date)} +
                            " " +
                            string{begin((it + 1)->date) + 3, end((it + 1)->date)} +
                            " " +
                            to_string(minutes) +
                            " $",
                        prices
                    }
                );
                advance(it, 2);
            } else {
                break;
            }
        }
        result.total_amount = total_amount;
        if (total_amount != 0) {
            bills.push_back(result);
        }
    }
    for (auto& e: bills) {
        cout << e.name_and_month << "\n";
        for (auto& p: e.call_data) {
            printf("%s%.2f\n", p.time.c_str(), p.costs);
        }
        printf("Total amount: $%.2f\n", e.total_amount);
    }
}