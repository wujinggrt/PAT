#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

struct Stu {
  string card_no;
  int score;
};

int main() {
  freopen("i.dat", "r", stdin);
  int n, m;
  cin >> n >> m;
  vector<Stu> students(n);
  unordered_map<string, vector<Stu>> level;
  unordered_map<string, vector<Stu>> site;
  unordered_map<string, vector<Stu>> date;
  for (int i = 0; i < n; ++i) {
    string card_number;
    int score;
    cin >> card_number >> score;
    auto iter = begin(card_number);
    string cur_level{*iter};
    level[cur_level].push_back(Stu{card_number, score});
    ++iter;
    string cur_site{iter, iter + 3};
    site[cur_site].push_back(Stu{card_number, score});
    iter += 3;
    string cur_date{iter, iter + 6};
    date[cur_date].push_back(Stu{card_number, score});
    iter += 6;
  }
  for (int i = 1; i <= m; ++i) {
    int type;
    string term;
    cin >> type >> term;
    cout << "Case " << i << ": " << type << " " << term << "\n";
    if (type == 1) {
      auto iter = level.find(term);
      if (iter == end(level)) {
        cout << "NA\n";
        continue;
      }
      auto vec = iter->second;
      sort(begin(vec), end(vec), [&] (Stu lhs, Stu rhs) {
        return lhs.score != rhs.score ? lhs.score > rhs.score : lhs.card_no < rhs.card_no;
      });
      for (auto item: vec) {
        cout << item.card_no << " " << item.score << "\n";
      }
    } else if (type == 2) {
      auto iter = site.find(term);
      if (iter == end(site)) {
        cout << "NA\n";
        continue;
      }
      auto vec = iter->second;
      cout << vec.size() << " " << accumulate(begin(vec), end(vec), 0, [&] (int acc, Stu stu) { return acc + stu.score; }) << "\n";
    } else if (type == 3) {
      auto iter = date.find(term);
      if (iter == end(date)) {
        cout << "NA\n";
      } else {
        unordered_map<string, vector<Stu>> temp_sites;
        for (auto stu: iter->second) {
          string cur_site{begin(stu.card_no) + 1, begin(stu.card_no) + 4};
          temp_sites[cur_site].push_back(stu);
        }
        vector<pair<string, int>> ans;
        for (auto entry: temp_sites) {
          ans.push_back({entry.first, entry.second.size()});
        }
        sort(begin(ans), end(ans), [] (decltype(ans.front()) lhs, decltype(ans.front()) rhs) {
          return lhs.second != rhs.second ? lhs.second > rhs.second : lhs.first < rhs.first;
        });
        for (auto p: ans) {
          cout << p.first << " " << p.second << "\n";
        }
      }
    }
  }
}
