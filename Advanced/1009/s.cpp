#include <map>
#include <utility>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int former_cnt;
	cin >> former_cnt;
	vector<pair<int, double>> former(former_cnt);
	for (int i = 0; i < former_cnt; ++i) {
		cin >> former[i].first >> former[i].second;
	}
	int latter_cnt;
	cin >> latter_cnt;
	vector<pair<int, double>> latter(latter_cnt);
	for (int i = 0; i < latter_cnt; ++i) {
		cin >> latter[i].first >> latter[i].second;
	}
	map<int, double> result;
	for (int i = 0; i < former_cnt; ++i) {
		for (int j = 0; j < latter_cnt; ++j) {
			auto k = former[i].first + latter[j].first;
			auto n = former[i].second * latter[j].second;
			auto it = result.find(k);
			if (it != result.end()) {
				it->second += n;
				if (it->second == 0) {
					result.erase(it);
				}
			} else {
				result.emplace(k, n);
			}
		}
	}
	printf("%lu", result.size());
	auto it = result.crbegin();
	while (it != result.crend()) {
		printf(" %d %.1f", it->first, it->second);
		++it;
	}
}
