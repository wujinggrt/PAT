#include <algorithm>
#include <utility>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // n: windows, m:max capacity of yellow line, k:customers, q:asking
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<int> processing_time(k);
    for (auto &e: processing_time) {
        cin >> e;
    }
    vector<int> asking(q);
    for (auto &e: asking) {
        cin >> e;
    }
    // 总的时间等于 time_hour + time_minute % 60，只增加分的时间
    int time_minute = 0;
    // --service_cost[i]，当其存储值为0，则说明为空闲
    // 刷新时间，？分钟，还是最小的输入，每次遍历flag，找到最小值，减去他
    vector<int>  service_cost(n, 0);
    // 使用min_element可以找出最小的队列
    vector<vector<int>>  yellow_line_queue(n);
    // 从等待队列开始处理
    // 需要计算出每个顾客的完成时间
    unordered_map<int, pair<int, int>> finish_time;
    for (int i = 0; i < k; ) {
        // 更新黄线内部队列
        // 先把黄线内的队列排满，然后在处理
        // 添加的情况为，当这条队列有人完成服务后，离开而产生空缺
        while (i < k) {
            auto it_waiting = min_element(yellow_line_queue.begin(), 
                                          yellow_line_queue.end(), 
                                          [] (const auto &l, const auto &r) {
                                              return l.size() < r.size();
                                          });
            // 满员
            if (it_waiting->size() == m) {
                break;
            }
            it_waiting->push_back(i);
            // 第几号窗口在处理
            auto service_window = it_waiting - yellow_line_queue.begin();
            auto cost = 0;
            // 需要计算出这条队列中，**开始**处理队列首位的开始时间
            // 随后，使用 i的结束时间 = 开始时间 + 队列中每一个人的transaction time
            // 没有在处理
            if (service_cost[service_window] == 0) {
                cost = time_minute;
            } else {
                // time_minute + service_cost[service_window]为处理完第一个人后的时间
                cost = time_minute + service_cost[service_window] - processing_time[it_waiting->front()];
            }
            for (const auto &e: *it_waiting) {
                cost += processing_time[e];
            }
            // cost - it_waiting->back()为开始处理这个客户的时间，加上时间后为结束时间
            finish_time[i] = make_pair(cost - processing_time[it_waiting->back()], cost);
            ++i;
        }
        // 由队列第一人的时间来更新处理窗口
        // 扫描每个处理窗口，如果空闲，且队列非空，则开始处理
        for (int j = 0; j < n; ++j) {
            if (!yellow_line_queue[j].empty() && service_cost[j] == 0) {
                service_cost[j] = processing_time[yellow_line_queue[j].front()];
            }
        }
        // 推进时间
        // 服务进行，找到最小的，且不为0的。
        // 服务完成后，这个窗口的第一个队列者弹出，然后结束，到循环里更新队列
        // 或许这儿可以优化下队列的更新方案，就在这儿更新队列，不用扫描整个窗口。
        // 因为0代表着空闲，没有足够多的业务来处理了，逼近结束。
        auto min_cost = *min_element(
            service_cost.begin(), 
            service_cost.end(), 
            [] (const auto &l, const auto &r) {
                // 如果全部为0，这组数据跳过
                // 如果其中有一个为0，那么取大的
                if (l == 0 && r != 0) {
                    return false;
                } else if (l != 0 && r == 0) {
                    return true;
                } else {
                    return l < r;
                }
        });
        // 时间增加服务时间时间最短的窗口部分
        if (min_cost != 0) {
            // 存储相同时间离开的客户
            vector<int> leaving;
            for (auto i = 0; i < n; ++i) {
                if (service_cost[i] != 0) {
                    service_cost[i] -= min_cost;
                    if (service_cost[i] == 0) {
                        leaving.push_back(i);
                    }
                }
            }
            time_minute += min_cost;
            for (const auto &e: leaving) {
                swap(yellow_line_queue[e].front(), yellow_line_queue[e].back());
                yellow_line_queue[e].pop_back();
            }
        }
    }
    for (auto &e: asking) {
        auto it = finish_time.find(e - 1);
        if (it == finish_time.end()) {
            continue;
        }
        auto [start, end] = it->second;
        // auto start = it->second.first;
        // auto end = it->second.second;
        auto hours = 8 + end / 60;
        auto minutes = end % 60;
        // 17点之后开始的，才会sorry
        if (start >= (17 - 8) * 60) {
            printf("Sorry\n");
        } else {
            printf("%02d:%02d\n", hours, minutes);
        }
    }
}