#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    double e;
    cin >> e;
    int d;
    cin >> d;
    int may_empty = 0;
    int is_empty = 0;
    for (int i = 0; i < n; ++i) {
        int k;
        int count = 0;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            double record;
            cin >> record;
            if (record < e) {
                ++count;
            }
        }
        if (count > (k / 2)) {
            ++may_empty;
            if (k > d) {
                ++is_empty;
                --may_empty;
            }
        }
    }
    double may_empty_percentage = static_cast<double>(may_empty) / n  * 100;
    double is_empty_percentage = static_cast<double>(is_empty) / n  * 100;
    printf("%.1f%% %.1f%%\n", may_empty_percentage, is_empty_percentage);
    return 0;
}