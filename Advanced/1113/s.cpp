#include <cstdio>

#include <numeric>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    for (auto& num: data) {
        cin >> num;
    }
    sort(begin(data), end(data));
    int num_former = n / 2;
    int num_latter = n - num_former;
    cout << abs(num_former - num_latter) << " ";
    auto iter = begin(data);
    int former = accumulate(iter, iter + num_former, 0);
    int latter = accumulate(iter + num_former, end(data), 0);
    cout << abs(latter - former) << "\n";
}