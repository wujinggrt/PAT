#include <cstdio>
#include <iostream>
using namespace std;

struct Charge {
    int galleon;
    int sickle;
    int knut;
};

int main() {
    Charge p;
    Charge a;
    scanf("%d.%d.%d %d.%d.%d", 
        &p.galleon, 
        &p.sickle,
        &p.knut,
        &a.galleon,
        &a.sickle,
        &a.knut
    );
    long long p_k = 17 * p.galleon * 29 + 29 * p.sickle + p.knut;
    long long a_k = 17 * a.galleon * 29 + 29 * a.sickle + a.knut;
    auto r_k = a_k - p_k;
    int g = r_k / (17 * 29);
    int s = (r_k / 29) % 17;
    int k = r_k % 29;
    cout << (r_k < 0 ? "-" : "");
    printf("%d.%d.%d\n", abs(g), abs(s), abs(k));
    return 0;
}