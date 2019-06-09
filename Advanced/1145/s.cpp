#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool is_prime(int num) {
  if (num < 2) {
    return false;
  }
  if (num == 2 || num == 3) {
    return true;
  }
  for (int i = 2; i < sqrt(num) + 1; ++i) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  freopen("i.dat", "r", stdin);
  int m_size, n, m;
  cin >> m_size >> n >> m;
  for (; !is_prime(m_size); ++m_size) {
  }
  // -1 stands empty
  vector<int> table(m_size, -1);
  for (; n-- > 0; ) {
    int num;
    cin >> num;
    auto inserted = [&] () {
      for (int i = 0; i < m_size; ++i) {
        int pos = (num + i * i) % m_size;
        if (table[pos] == -1) {
          table[pos] = num;
          return true;
        }
      }
      return false;
    } ();
    if (!inserted) {
      printf("%d cannot be inserted.\n", num);
    }
  }
  int search_time = 0;
  for (int i = 0; i < m; ++i) {
    int num;
    cin >> num;
    for (int j = 0; j <= m_size; ++j) {
      int pos = (num + j * j) % m_size;
      ++search_time;
      if (table[pos] == num || table[pos] == -1) {
        break;
      }
    }
  }
  printf("%.1lf\n", (double) search_time / m);
}
