#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct Testee {
    string id;
    int32_t score;
    int32_t final_rank;
    int32_t location;
    int32_t local_rank;
};

int main() {
    int32_t n;
    cin >> n;
    vector<vector<Testee>> ranklists(n);
    int32_t testee_cnt = 0;
    for (int32_t i = 0; i < n; ++i) {
        int32_t k;
        cin >> k;
        testee_cnt += k;
        ranklists[i] = vector<Testee> (k);
        for (auto& testee: ranklists[i]) {
            cin >> testee.id >> testee.score;
            testee.location = i + 1;
        }
        sort(begin(ranklists[i]), end(ranklists[i]), [] (auto& l, auto& r) {
            if (l.score == r.score) {
                return l.id < r.id;
            } else {
                return l.score > r.score;
            }
        });
        // 如果相同，那么排名相同
        int32_t rank_tmp = -1;
        for (int32_t j = 0; j < k; ++j) {
            if (ranklists[i][j].score != rank_tmp) {
                rank_tmp = ranklists[i][j].score;
                ranklists[i][j].local_rank = j + 1;
            } else {
                ranklists[i][j].local_rank = ranklists[i][j - 1].local_rank;
            }
        }
    }
    vector<Testee> dst;
    dst.reserve(testee_cnt);
    for (auto& local: ranklists) {
        for (auto& testee: local) {
            dst.push_back(testee);
        }
    }
    sort(begin(dst), end(dst), [] (auto& l, auto& r) {
        if (l.score == r.score) {
            return l.id < r.id;
        } else {
            return l.score > r.score;
        }
    });
    int32_t rank_tmp = -1;
    for (int32_t i = 0; i < testee_cnt; ++i) {
        if (rank_tmp != dst[i].score) {
            dst[i].final_rank = i + 1;
            rank_tmp = dst[i].score;
        } else {
            dst[i].final_rank = dst[i - 1].final_rank;
        }
    }
    cout << testee_cnt << "\n";
    for (auto& testee: dst) {
            printf("%s %d %d %d\n",
                                  testee.id.c_str(),
                                  testee.final_rank,
                                  testee.location,
                                  testee.local_rank);
    }
}