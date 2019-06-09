#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  freopen("i.dat", "r", stdin);
  int n;
  cin >> n;
  vector<int> nums(n, 0);
  for ([[maybe_unused]]auto t: nums) {
    int num;
    cin >> num;
    if (num <= n && num > 0) {
      nums[num - 1] = 1;
    }
  }
  int ans = 0;
  for (; ans < n; ++ans) {
    if (nums[ans] == 0) {
      break;
    }
  }
  cout << (ans + 1) << endl;
}
