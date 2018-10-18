#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    unsigned long c1, c2;
    cin >> c1 >> c2;
    auto span = static_cast<unsigned long>((c2 - c1) / 100. + 0.5);
    auto second = span % 60;
    auto min = (span / 60) % 60;
    auto hour = span / 3600;
    printf("%02d:%02d:%02d\n", hour, min, second);
    return 0;
}