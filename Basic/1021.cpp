#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string k;
    cin >> k;
    vector<int> vec(10, 0);
    for (const auto &c: k)
    {
        ++vec[c - '0'];
    }
    for (int i = 0; i < 10; ++i)
    {
        if (!vec[i])
        {
            continue;
        }
        cout << i << ":" << vec[i] << '\n';
    }
    return 0;
}