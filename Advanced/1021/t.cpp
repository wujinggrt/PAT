#include <iostream>
#include <vector>
using namespace std;

int main() {
    int32_t n = 10000;
    vector<vector<int32_t>> vec(n, vector<int32_t>(n, 0));
    cout << vec.size() << "\n";
}