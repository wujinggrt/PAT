#include <vector>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int32_t n1 = 3;
    int32_t n2 = 3;
    int32_t n3 = n1;
    int32_t N = s.size();
    auto result = N + 2;
    // find n1 n2 n3
    for (int32_t n = 1; ; ) {
        auto n2_tmp = result - 2 * n;
        if (n2_tmp >= n) {
            n1 = n3 = n;
            n2 = n2_tmp;
            ++n;
        } else {
            break;
        }
    }
    vector<string> squares;
    squares.reserve(n1);
    for (size_t i = 0; i < n1; ++i) {
        string blank_part(n2 - 2, ' ');
        string line = s[i] + blank_part + s[s.size() - 1 - i];
        squares.push_back(std::move(line));
    }
    for (size_t i = 1; i < n2 - 1; ++i) {
        squares[n1 - 1][i] = s[n1 + i - 1];
    }
    for (auto& line: squares) {
        cout << line << "\n";
    }
}