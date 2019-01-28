#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Player {
    bool is_vip;
    // 时间用秒来记
    int32_t arrive;
    int32_t start_playing;
    int32_t playing;
    // 使用分来计算
    int32_t waiting;
};

struct Table {
    bool is_vip;
    int32_t open_time;
    int32_t serve_cnt;
};

static const int open_time = 8 * 3600;
static const int close_time = 21 * 3600;

int main() {
    int n;
    cin >> n;
    vector<Player> vips;
    vector<Player> ordinaries;
    for (int32_t i = 0; i < n; ++i) {
        int32_t h, m, s, playing, tag;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &playing, &tag);
        Player p{
                 (tag == 0 ? false : true),
                 h * 3600 + m * 60 + s,
                 h * 3600 + m * 60 + s,
                 playing * 60,
                 0};
        if (p.arrive >= close_time) {
            continue;
        }
        if (p.is_vip) {
            vips.push_back(std::move(p));
        } else {
            ordinaries.push_back(std::move(p));
        }
    }
    auto cmp = [] (auto& l, auto& r) {
        return l.arrive > r.arrive;
    };
    make_heap(begin(vips), end(vips), cmp);
    make_heap(begin(ordinaries), end(ordinaries), cmp);
    int32_t k, m;
    cin >> k >> m;
    vector<Table> tables(k, Table {false, open_time, 0});
    for (int32_t i = 0; i < m; ++i) {
        int32_t vip_no;
        cin >> vip_no;
        tables[vip_no - 1].is_vip = true;
    }
    vector<Player> played;
    played.reserve(vips.size() + ordinaries.size());
    while (!ordinaries.empty() || !vips.empty()) {
        size_t min_table = INT32_MAX;
        int32_t min_time = INT32_MAX;
        size_t min_vip_table = INT32_MAX;
        int32_t min_vip_time = INT32_MAX;
        // 找到最先open的table，以及vip的
        for (size_t i = 0; i < tables.size(); ++i) {
            if (tables[i].open_time < min_time) {
                min_time = tables[i].open_time;
                min_table = i;
            }
            if (
                tables[i].is_vip && 
                tables[i].open_time < min_vip_time
            ) {
                min_vip_time = tables[i].open_time;
                min_vip_table = i;
            }
        }
        // 闭馆
        if (tables[min_table].open_time >= close_time) {
            break;
        }
        // 找到下一个player
        Player player;
        auto choose_player = [&] (auto& players) {
            pop_heap(begin(players), end(players), cmp);
            player = std::move(players.back());
            players.pop_back();
        };
        if (ordinaries.empty()) {
            choose_player(vips);
        } else if (vips.empty()) {
            choose_player(ordinaries);
        } else {
            if (tables[min_table].is_vip) {
                if (
                    vips.front().arrive < ordinaries.front().arrive || 
                    tables[min_table].open_time > vips.front().arrive
                ) {
                    choose_player(vips);
                } else {
                    choose_player(ordinaries);
                }
            } else {
                if (vips.front().arrive < ordinaries.front().arrive) {
                    choose_player(vips);
                } else {
                    choose_player(ordinaries);
                }
            }
        }
        // 不能超过2小时
        if (player.playing > 2 * 3600) {
            player.playing = 2 * 3600;
        }
        // 更新table信息
        if (
            player.is_vip &&
            player.arrive >= tables[min_vip_table].open_time
        ) {
            player.start_playing = player.arrive;
            player.waiting = 0;
            
            tables[min_vip_table].open_time = player.arrive + player.playing;
            ++tables[min_vip_table].serve_cnt;
        } else if (player.arrive <= tables[min_table].open_time) {
            player.start_playing = tables[min_table].open_time;
            player.waiting = tables[min_table].open_time - player.arrive;

            tables[min_table].open_time += player.playing;
            ++tables[min_table].serve_cnt;
        } else {
            player.start_playing = player.arrive;
            player.waiting = 0;

            tables[min_table].open_time = player.arrive + player.playing;
            ++tables[min_table].serve_cnt;
        }
        played.push_back(std::move(player));
    }
    sort(begin(played), end(played), [] (auto& l, auto& r) {
        return l.start_playing < r.start_playing;
    });
    for (auto& player: played) {
        auto minute = player.waiting / 60 + (player.waiting % 60 < 30 ? 0 : 1);
        printf(
            "%02d:%02d:%02d %02d:%02d:%02d %d\n",
            player.arrive / 3600,
            player.arrive % 3600 / 60,
            player.arrive % 60,
            player.start_playing / 3600,
            player.start_playing % 3600 / 60,
            player.start_playing % 60,
            minute);
    }
    bool first = true;
    for (auto& table: tables) {
        if (first) {
            first = false;
        } else {
            cout << " ";
        }
        cout << table.serve_cnt;
    }
    cout << "\n";
}