#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;

inline int get_left(int i) { return 2 * i + 1; }

inline int get_right(int i) { return 2 * i + 2; }

int main() {
  freopen("i.dat", "r", stdin);
  int n;
  cin >> n;
  vector<int> level_order{istream_iterator<int>(cin), istream_iterator<int>()};
  vector<int> track;
  track.reserve(n);
  // 1 max_heap
  // 2 min_heap
  // 3 not heap
  int heap_type = 0;
  function<void(int)> dfs =
    [&] (int index) {
    if (index >= n) {
      return ;
    }
    track.push_back(level_order[index]);
    int right = get_right(index);
    int left = get_left(index);
    if (right < n) {
      if (level_order[index] > level_order[right]) {
        heap_type |= 1;
      } else if (level_order[index] < level_order[right]) {
        heap_type |= 2;
      }
    }
    if (left < n) {
      if (level_order[index] > level_order[left]) {
        heap_type |= 1;
      } else if (level_order[index] < level_order[left]) {
        heap_type |= 2;
      }
    }
    dfs(right);
    dfs(left);
    // the leaf node
    if (index >= n / 2) {
      bool is_first = true;
      for (auto num: track) {
        cout << (is_first ? "" : " ") << num;
        is_first = false;
      }
      cout << "\n";
    }
    track.pop_back();
    };
  dfs(0);
  // is_heap(begin(level_order)...
  //cout << (heap_type == 3 ? "Not " :
                            //heap_type == 2 ? "Min " : "Max ") << "Heap\n";
  auto res = is_heap(begin(level_order), end(level_order));
  if (res) {
    cout << "Max Heap\n";
  } else {
    res = is_heap(begin(level_order), end(level_order), greater<int>());
    cout << (res ? "Min Heap\n" : "Not Heap\n");
  }
}
