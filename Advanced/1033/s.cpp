#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct Station {
    int32_t dis;
    double price;
};

int main() {
    int32_t c_max, d, d_avg, n;
    cin >> c_max >> d >> d_avg >> n;
    vector<Station> stations(n);
    stations.reserve(n + 1);
    for (auto& e: stations) {
        cin >> e.price >> e.dis;
    }
    stations.push_back(std::move(Station{d, 0}));
    sort(begin(stations), end(stations), [] (const auto& l, const auto& r) {
        return l.dis < r.dis;
    });
    int32_t max_forward = c_max * d_avg;
    double total = 0.;
    int32_t cur_dis = 0;
    int32_t left_drive = 0;
    for (size_t cur = 0; cur < n;) {
        // 每一次都应该到达加油站，否则不能跑了
        if (stations[cur].dis != cur_dis) {
            break;
        }
        double min_price = INT32_MAX;
        int32_t min_idx = -1;
        for (size_t i = cur + 1; i <= n; ++i) {
            if (stations[i].dis <= cur_dis + max_forward) {
                if (stations[i].price < stations[cur].price) {
                    min_price = stations[i].price;
                    min_idx = i;
                    break;
                }
                // 没有找到比当前站便宜的station，就从能到的之后最便宜的地方加油
                if (stations[i].price < min_price) {
                    min_price = stations[i].price;
                    min_idx = i;
                }
            }
        }
        if (min_idx == -1) {
            cur_dis = max_forward + stations[cur].dis;
            break;
        } else {
            if (min_price < stations[cur].price) {
                total += (
                    static_cast<double>(stations[min_idx].dis - stations[cur].dis) / d_avg -
                    static_cast<double>(left_drive) / d_avg 
                    ) * stations[cur].price;
                left_drive = 0;
                cur = min_idx;
            } else {
                // 加满
                double left_gas = static_cast<double>(left_drive) / d_avg;
                total += (static_cast<double>(c_max) - left_gas) * stations[cur].price;
                left_drive = max_forward - 
                            (stations[min_idx].dis - stations[cur].dis);
                cur = min_idx;
            }
            cur_dis = stations[min_idx].dis;
        }
    }
    if (cur_dis == d) {
        printf("%.2f\n", total);
    } else {
        printf("The maximum travel distance = %.2f\n", static_cast<double>(cur_dis));
    }
}