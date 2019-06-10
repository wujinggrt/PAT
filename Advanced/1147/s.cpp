#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  freopen("i.dat", "r", stdin);
  int m, n;
  cin >> m >> n;
  for (; m-- != 0; ) {
    vector<int> heap(n);
    for (auto& num: heap) {
      cin >> num;
    }
    bool is_heap = true;
    bool is_max_heap = heap[0] > heap[1];
    for (int i = 0; i != n; ++i) {
      int left = i * 2 + 1;
      int right = left + 1;
      if (is_max_heap) {
        if ((left < n) && (heap[i] < heap[left])) {
          is_heap = false;
          break;
        }
        if ((right < n) && (heap[i] < heap[right])) {
          is_heap = false;
          break;
        }
      } else {
        if ((left < n) && (heap[i] > heap[left])) {
          is_heap = false;
          break;
        }
        if ((right < n) && (heap[i] > heap[right])) {
          is_heap = false;
          break;
        }
      }
    }
    if (!is_heap) {
      cout << "Not Heap\n";
    } else {
      if (is_max_heap) {
        cout << "Max Heap\n";
      } else {
        cout << "Min Heap\n";
      }
    }
    bool is_front = true;
    function<void(int)> postorder = [&] (int index) {
      int left = index * 2 + 1;
      int right = left + 1;
      if (left < n) {
        postorder(left);
      }
      if (right < n) {
        postorder(right);
      }
      cout << (is_front ? "" : " ") << heap[index];
      is_front = false;
    };
    postorder(0);
    cout << "\n";
  }
}
