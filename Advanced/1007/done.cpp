#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	int left = 0;
	int right = n - 1;
	int sum = -1;
	int temp = 0;
	int temp_index = 0; // for left
	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
		temp = temp + vec[i];
		if (temp < 0) { // 舍弃当前连续点
			temp = 0;
			temp_index = i + 1; 
		} else if (temp > sum) { // 最大值, 不选择=是为了最小的index
			sum = temp;
			left = temp_index;
			right = i;
		}
	}
	if (sum < 0) {
		sum = 0;
	}
	printf("%d %d %d\n", sum, vec[left], vec[right]);
}
