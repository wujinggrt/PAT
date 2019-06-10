#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool is_prime(int i) {
  if (i < 2) {
    return false;
  }
  if (i == 2 || i == 3) {
    return true;
  }
  for (int j = 2; j < sqrt(i) + 1; ++j) {
    if (i % j == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  freopen("i2.dat", "r", stdin);
  int l, k;
  cin >> l >> k;
  string num;
  cin >> num;
  auto iter = begin(num);
  for (int i = 0; i + k <= num.size(); ++i) {
    string s{iter, iter + k};
    auto number = stoi(s);
    if (is_prime(number)) {
      cout << s << "\n";
      exit(0);
    }
    ++iter;
  }
  cout << 404 << endl;
}
