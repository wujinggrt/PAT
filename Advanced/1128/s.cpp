#include <cmath>
#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        vector<int> chessboard(num);
        bool ans = true;
        for (int j = 0; j < num; ++j) {
            cin >> chessboard[j];
            for (int z = 0; z < j; ++z) {
                if (chessboard[z] == chessboard[j] || abs(chessboard[z] - chessboard[j]) == abs(z - j)) {
                    ans = false;
                }
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}
