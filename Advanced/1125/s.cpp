#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ropes{istream_iterator<int>(cin), istream_iterator<int>()};
    sort(begin(ropes), end(ropes));
    // 为了在第一个 (ans + ans) / 2 == ans
    int ans = ropes.front();
    for_each(begin(ropes) + 1, end(ropes), [&] (int num) {
        ans = (ans + num) / 2;
    });
    cout << ans << "\n";
    return 0;
}