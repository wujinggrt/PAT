#include <iostream>
#include <string>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

int main() {
    vector<int32_t> vec{4, 3, 9, 6};
    priority_queue<int32_t, vector<int32_t>, less<int32_t>> q{begin(vec), end(vec)};
    for (int i = 0; i < 4; ++i) {
        cout << q.top() << "\n";
        q.pop();
    }
}