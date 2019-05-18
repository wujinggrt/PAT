#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    int m, n, s;
    cin >> m >> n >> s;
    vector<string> forwards{istream_iterator<string>(cin), istream_iterator<string>()};
    if (s > m) {
        cout << "Keep going...\n";
    } else {
        int index = s - 1;
        unordered_set<string> winners;
        // insert ok
        while (index < forwards.size()) {
            if (winners.insert(forwards[index]).second) {
                cout << forwards[index] << "\n";
                index += n;
            } else {
                ++index;
            }
        }
    }
    return 0;
}