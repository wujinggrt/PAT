#include <iostream>
#include <vector>
using namespace std;

const int MOVE_UP_TIME = 6;
const int MOVE_DOWN_TIME = 4;
const int STAY_TIME = 5;

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; ++i) {
		cin >>vec[i];
	}
	int cur_floor = 0;
	int total_cost = 0;
	for (int i = 0; i < n; ++i) {
		total_cost += (cur_floor < vec[i] ? 
					   MOVE_UP_TIME * (vec[i] - cur_floor) :
					   MOVE_DOWN_TIME * (cur_floor - vec[i])
					   ) + STAY_TIME;
		cur_floor = vec[i];
	}
	printf("%d\n", total_cost);	
}
