#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> origin(n);
    for (auto& num: origin) {
        cin >> num;
    }
    vector<int> target(n);
    for (auto& num: target) {
        cin >> num;
    }
    int pos = 1;
    for (; pos < n - 1; ++pos) {
        if (target[pos] < target[pos - 1]) {
            break;
        }
    }
    bool is_insertion = equal(begin(target) + pos + 1, end(target), begin(origin) + pos + 1);
    if (is_insertion) {
        sort(begin(target), begin(target) + pos + 1);
        cout << "Insertion Sort\n";
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                cout << " ";
            }
            cout << target[i];
        }
    } else {
        make_heap(begin(origin), end(origin));
        int num_pop = 0;
        for (; num_pop < n; ++num_pop) {
            if (origin == target) {
                break;
            }
            pop_heap(begin(origin), end(origin) - num_pop);
        }
        pop_heap(begin(origin), end(origin) - num_pop);
        cout << "Heap Sort\n";
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                cout << " ";
            }
            cout << origin[i];
        }
    }
    cout << "\n";
}