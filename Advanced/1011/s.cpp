#include <tuple>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

static const char* max_profit[] = {"W", "T", "L"};

int main() {
    vector<vector<double>> rate(3, vector<double>(3, 0));
    for (int i = 0; i < 3; ++i) {
        cin >> rate[i][0] >> rate[i][1] >> rate[i][2];
    }
    auto [max_1, max_2, max_3] = make_tuple(
        max_element(rate[0].begin(), rate[0].end()),
        max_element(rate[1].begin(), rate[1].end()),
        max_element(rate[2].begin(), rate[2].end())
        );
    printf("%s %s %s %.2f\n", 
            max_profit[distance(rate[0].begin(), max_1)],
            max_profit[distance(rate[1].begin(), max_2)],
            max_profit[distance(rate[2].begin(), max_3)],
            ((*max_1) * (*max_2) * (*max_3) * 0.65 - 1) * 2
    );
}