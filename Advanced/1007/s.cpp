#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
	int k;
	cin >> k;
	vector<int> vec(k);
	for (int i = 0; i < k; ++i) {
		cin >> vec[i];
	}
	// 对于 0 <= k <= i - 1，有sequence_sum[i] = vec[k..i]的和，
	// 使其为最大值，其中vec[k..i - 1]的和肯定小于0，使得vec[k..i - 1] + vec[i]局域最大
	// sequence_sum[-1] = 0
	// 即sequence_sum[i] = max{vec[i], sequence_sum[i - 1] + vec[i]}
	vector<int> sequence_sum(k, 0);
	vector<int> left(k, 0);
	// max_tmp是vec[k..i - 1]的累积和，即vec[0..i - 1]的最大连续子序列
	int max_temp = 0;
	int left_temp = 0;
	int sum = -1;
	int l = 0;
	int r = k - 1;
	// bottom-up dp
	for (int i = 0; i < k; ++i) {
		max_temp += vec[i];
		// 不能=，因为需要最小的indices， 不然断了，index会增大
		// e.g. 1 2 -3 4, =的情况为[0, 3]，不等于[3, 3]
		if (max_temp < 0) { 
			sequence_sum[i] = max_temp;
			max_temp = 0;
			left[i] = left_temp;
			// left从下一个位置开始
			left_temp = i + 1;
		} else {
			sequence_sum[i] = max_temp;
			left[i] = left_temp;
			if (max_temp > sum) {
				sum = max_temp;
				l = left_temp;
				r = i;
			}
		}
	}
	int max_index = 0;
	for  (int i = 0; i < k; ++i) {
		if (sequence_sum[max_index] < sequence_sum[i]) {
			max_index = i;
		}
		printf("%d-%d ", sequence_sum[i], left[i]);
	}
	cout << "\n";
	sum = sum < 0 ? 0 : sum;
	printf("%d %d %d\n", sum, vec[l], vec[r]);
}