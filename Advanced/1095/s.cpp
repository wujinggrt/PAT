#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

struct Record {
	string plate;
	int time;
	int flag;
};

int main() {
	int n, k;
	cin >> n >> k;
	vector<Record> records;
	for (int i = 0; i < n; ++i) {
		string plate;
		string status;
		cin >> plate;
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int time = h * 3600 + m * 60 + s;
		cin >> status;
		records.push_back({plate, time, (status == "in" ? 1 : -1)});
	}
	sort(begin(records), end(records), [] (auto& lhs, auto& rhs) {
		if (lhs.plate != rhs.plate) {
			return lhs.plate < rhs.plate;
		} else {
			return lhs.time < rhs.time; // non-decreasing
		}
	});
	vector<Record> cars;
	map<string, int> stay;
	int max_stay = -1;
	for (int i = 0; i < records.size() - 1; ++i) {
		if (records[i].plate == records[i + 1].plate &&
				records[i].flag == 1 && /* in*/
				records[i + 1].flag == -1) { // out
			cars.push_back(records[i]);
			cars.push_back(records[i + 1]);
			int cur_stay = records[i + 1].time - records[i].time;
			string cur_car = records[i].plate;
			stay[cur_car] += cur_stay;
			if (max_stay < stay[cur_car]) {
				max_stay = stay[cur_car];
			}
		}
	}
	sort(begin(cars), end(cars), [] (auto& lhs, auto& rhs) {
		return lhs.time < rhs.time;
	});
	// vector<int> num_cur_car(cars.size(), 0);
	// for (int i = 0; i < cars.size(); ++i) {
	// 	if (i == 0) {
	// 		num_cur_car[i] += cars[i].flag;
	// 	} else {
	// 		num_cur_car[i] = num_cur_car[i - 1] + cars[i].flag;
	// 	}
	// }
	vector<int> queries(k);
	for (auto& q: queries) {
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		q = h * 3600 + m * 60 + s;
		int cur_num = 0;
		for (int i = 0; i < cars.size(); ++i) {
			if (cars[i].time <= q) {
				cur_num += cars[i].flag;
			} else {
				break;
			}
		}
		cout << cur_num << "\n";
	}
	for (auto& entry: stay) {
		if (entry.second == max_stay) {
			printf("%s ", entry.first.c_str());
		}
	}
	printf("%02d:%02d:%02d\n", max_stay / 3600, (max_stay % 3600) / 60, max_stay % 60);
}