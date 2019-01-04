#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int drinking_a = 0;
    int drinking_b = 0;
    for (int i = 0; i < n; ++i) {
        int saying_a;
        int performing_a;
        int saying_b;
        int performing_b;
        cin >> saying_a >> performing_a >> saying_b >> performing_b;
        auto result = saying_a + saying_b;
        if (performing_a == performing_b) {
            continue;
        } else if (performing_a == result) {
            ++drinking_b;
        } else if (performing_b == result) {
            ++drinking_a;
        }
    }
    cout << drinking_a << " " << drinking_b << '\n';
    return 0;
}