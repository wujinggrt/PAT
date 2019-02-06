#include <iostream>
using namespace std;

void count_one(int32_t n) {
    int32_t factor = 1;
    int32_t higher;
    int32_t lower;
    int32_t cur;
    int32_t cnt = 0;
    while (n / factor != 0) {
        higher = n / (factor * 10);
        lower = n - (n / factor) * factor;
        cur = n / factor % 10;
        if (cur == 0) {
            cnt += higher * factor;
        } else if (cur == 1) {
            // + 1 是因为cur这一个1
            cnt += higher * factor + lower + 1;
        } else {
            //  + 1 * factor 是因为10 - 19，也就是 1* 这个factor个1
            cnt += (higher + 1) * factor;
        }
        factor *= 10;
    }
    cout << cnt << "\n";
}

int main() {
    int32_t n;
    cin >> n;
    count_one(n);
}