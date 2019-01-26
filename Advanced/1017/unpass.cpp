// 来早的先排队等待
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Customer {
    string waiting;
    int32_t processing_time;
};

struct Window {
    int32_t customer;
    int32_t time_costs;
};

void waiting_time(const string& s) {
    int32_t hour;
    int32_t minute;
    int32_t second;
    sscanf(s.c_str(), "%2d:%2d:%2d", &hour, &minute, &second);
    cout << hour << " " << minute << " " << second << "\n";
}

int main() {
    int32_t n, k;
    cin >> n >> k;    
    vector<Customer> customers(n);
    for (auto& e: customers) {
        cin >> e.waiting >> e.processing_time;
    }
    sort(begin(customers), end(customers), [] (auto& l, auto& r) {
        return l.waiting < r.waiting;
    });
    auto it_early = find_if(begin(customers), end(customers), [] (auto& e) {
        return e.waiting >= "08:00:00"s;
    });
    vector<string> temp{"17:00:00"};
    auto it_late = find_if(begin(customers), end(customers), [] (auto& e) {
        return e.waiting > "17:00:00"s;
    });
    customers.erase(it_late, end(customers));
    n = customers.size();
    vector<Window> windows(k);
    auto cmp = [] (Window& l, Window& r) {
                                            if (l.time_costs == 0 && r.time_costs == 0) {
                                                return false;
                                            } else if (l.time_costs * r.time_costs == 0) {
                                                return false;
                                            } else {
                                                return l.time_costs < r.time_costs; 
                                            }
                                        };
    for (auto& e: customers) {
        cout << e.waiting << " " << e.processing_time << "\n";
    }                        
    int32_t hour = 8;
    int32_t minute = 0;
    int32_t second = 0;
    vector<int32_t> total_waiting(n);
    for_each(begin(customers), it_early, [] (auto& e) {
        waiting_time(e.waiting);
    });
    for (auto i = 0; i < n; ) {
        // 给窗口找到服务对象
        while (i < n) {
            auto it = find_if(begin(windows), end(windows), [] (auto& e) {
                return e.time_costs == 0;
            });
            if (it == end(windows)) {
                break;
            }
            it->customer = i;
            it->time_costs = customers[i].processing_time;
            total_waiting[i] += minute + it->time_costs;
            ++i;
        }
        // 找到最先处理完成的窗口，然后进行更新时间
        // 如果没有找到，全部处理完了
        auto min_cost = min_element(begin(windows), end(windows), cmp)->time_costs;
        for (auto& e: windows) {
            if (e.time_costs != 0) {
                e.time_costs -= min_cost;
            }
        }
    }
    for (auto& e: total_waiting) {
        cout << e << "\n";
    }
}