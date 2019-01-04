#include <tuple>
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	cin >> n;		
	vector<tuple<string, string, string>> vec(n);
	for (int i = 0; i < n; ++i) {
		string id;
		string in_time;
		string out_time;
		cin >> id >> in_time >> out_time;
		vec[i] = make_tuple(id, in_time, out_time);
	}
	int lock_door = 0;
	int unlock_door = 0;
	for (int i = 0; i < n; ++i) {
		if (get<1>(vec[i]) < get<1>(vec[unlock_door])) {
			unlock_door = i;
		}
		if (get<2>(vec[i]) > get<2>(vec[lock_door])) {
			lock_door = i;
		}
	}
	cout << get<0>(vec[unlock_door]) << " " << get<0>(vec[lock_door]) << "\n";
}
