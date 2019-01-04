#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;
    auto it = s.cbegin();
    char real_sign = *it++;
    int real = *it++ - '0';
    int fraction_part = 0;
    char expr_sign;
    int expr = 0;
    bool fraction = false;
    vector<char> vec;
    vec.reserve(20);
    for (; it != s.cend(); ++it)
    {
        if (*it == '.')
        {
            continue;
        }
        if (*it == 'E')
        {
            fraction = true;
            expr_sign = *++it;
            continue;
        }
        if (!fraction)
        {
            vec.push_back(*it);
        }
        else
        {
            expr = expr * 10 + (*it - '0');
        }
    }
    // 注意0开头的小数
    string frac(vec.begin(), vec.end());
    if (real_sign == '-')
    {
        cout << '-';
    }
    if (expr == 0 && real == 0 && frac == "0")
    {
        cout << 0;
    }
    else if (expr == 0)
    {
        cout << real << "." << frac;
    }
    else if (expr_sign == '+')
    {
        cout << real;
        int i = 0;
        for (; i < expr; ++i)
        {
            if (i < frac.size())
            {
                cout << frac[i];
            }
            else
            {
                cout << 0;
            }
        }
        if (i < frac.size())
        {
            cout << '.';
        }
        while (i < frac.size())
        {
            cout << frac[i];
            ++i;
        }
    }
    else
    {
        cout << "0.";
        int i = 1;
        for (; i < expr; ++i)
        {
            cout << 0;
        }
        cout << real << frac;
    }

    return 0;
}