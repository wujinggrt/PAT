#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums{istream_iterator<int>(cin), istream_iterator<int>()};
    set<int> ans;
    transform(begin(nums), end(nums), inserter(ans, begin(ans)), [] (int num) {
        int ret = 0;
        while (num != 0) {
            ret += num % 10;
            num /= 10;
        }
        return ret;
    });
    cout << ans.size() << "\n";
    bool first = true;
    for (auto num: ans) {
        if (first) {
            first = false;
        } else {
            cout << " ";
        }
        cout << num;
    }
}