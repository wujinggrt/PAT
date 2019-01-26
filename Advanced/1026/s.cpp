#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Player {
    int32_t arrive;
    int32_t stay;
    int32_t waiting;
    bool is_vip;
};

static const int open_time = 8 * 3600;
static const int close_time = 21 * 3600;

int main() {
    int n;
    cin >> n;
    vector<Player> vips;
    vector<Player> ordinaries;
    for (int32_t i = 0; i < n; ++i) {
        int32_t h, m, s, stay, tag;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &stay, &tag);
        if (tag == 0) {
            ordinaries.push_back(Player{
                                        h * 3600 + m * 60 + s,
                                        stay * 60,
                                        0,
                                        false});
        } else {
            vips.push_back(Player{
                                  h * 3600 + m * 60 + s,
                                  stay * 60,
                                  0,
                                  false});
        }
    }
    sort(begin(vips), end(vips), [] (auto& l, auto& r) {
        return l.arrive < r.arrive;
    });
    sort(begin(ordinaries), end(ordinaries), [] (auto& l, auto& r) {
        return l.arrive < r.arrive;
    });
    int32_t k, m;
    cin >> k >> m;
    vector<int32_t> tables(k);
    vector<int32_t> vip_tables(m);
    for (auto& e: vip_tables) {
        cin >> e;
        e -= 1;
    }
    int32_t last_ordinary = 0;
    int32_t ordinaries_free = k - m;
    int32_t vips_free = m;
    for (int32_t i = 0; i < n; ++i) {
        if ()
    }
}