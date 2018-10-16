#include <numeric>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int process(int n)
{
    vector<int> vec;
    vec.reserve(4);
    for (int i = 0; i < 4; ++i)
    {
        vec.push_back(n % 10);
        n /= 10;
    }
    
    sort(vec.begin(), vec.end());
    auto op = [](const int & l, const int & r) { return l * 10 + r;};
    int ascend = accumulate(vec.begin(), vec.end(), 0, op);
    sort(vec.begin(), vec.end(), [](auto l, auto r) { return l >= r;});
    int descend = accumulate(vec.begin(), vec.end(), 0, op);
    
    printf("%.4d - %.4d = %.4d\n", descend, ascend, descend - ascend);

    if (descend - ascend == 6174 || !(descend - ascend))
    {
        return 0;
    }
    
    return process(descend - ascend);
}

int main()
{
    int s;
    cin >> s;
    process(s);
    return 0;
}