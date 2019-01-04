#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool is_prime(unsigned n)
{
    if (n == 1)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }
    unsigned bound = sqrt(n) + 1;
    for (int i = 2; i < bound; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int m;
    int n;
    cin >> m >> n;
    vector<int> vec;
    vec.reserve(20);
    int cnt = 0;
    int num = 2;
    while (true)
    {
        if (is_prime(num))
        {
            ++cnt;
            if (cnt >= m)
            {
                vec.push_back(num);
            }
            if (cnt == n)
            {
                break;
            }
        }
        ++num;
    }
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i];
        if (i == vec.size() - 1)
        {
            break;
        }
        if (i % 10 == 9)
        {
            cout << "\n";
        }
        else
        {
            cout << " ";
        }
    }

    return 0;
}