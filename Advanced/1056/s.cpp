#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct Mouse {
    int32_t weight;
    int32_t rank;
};

int main() {
    int32_t n_p;
    int32_t n_m;
    cin >> n_p >> n_m;
    vector<Mouse> records(n_p);
    queue<int32_t> orders;
    for (auto& mouse: records) {
        cin >> mouse.weight;
    }
    for (int32_t i = 0; i < n_p; ++i) {
        int32_t order;
        cin >> order;
        orders.push(order);
    }
    // 将会剩下多少人参加下一轮 next_round
    int32_t remains = n_p;
    int32_t next_round = n_p;
    // 必须赛的场次数
    while (remains != 1) {
        next_round = remains / n_m + (remains % n_m != 0 ? 1 : 0);
        for (int32_t i = 0; i < next_round; ++i) {
            int32_t fattest = orders.front();
            // 每一次遍历一组
            for (int32_t j = 0; j < n_m; ++j) {
                auto front = orders.front();
                if (i * n_m + j >= remains) {
                    break;
                }
                if (records[fattest].weight < records[front].weight) {
                    fattest = front;
                }
                records[front].rank = next_round + 1;
                orders.pop();
            }
            orders.push(fattest);
        }
        remains = next_round;
    }
    records[orders.front()].rank = 1;
    bool first = true;
    for (auto& e: records) {
        if (first) {
            first = false;
        } else {
            cout << " ";
        }
        cout << e.rank;
    }
}