#include <functional>
#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> riding{istream_iterator<int>(cin), istream_iterator<int>()};
    sort(begin(riding), end(riding), greater<int>());
    int days = 0;
    for (int i = 1; i <= n; ++i) {
        if (riding[i - 1] > i) {
            ++days;
        }
    }
    cout << days << "\n";
}