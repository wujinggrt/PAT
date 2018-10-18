#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

void print_str(int n, int padding, string s)
{
    if (n <= 0)
    {
        return;
    }
    for (int i = 0; i < padding; ++i)
    {
        cout << " ";
    }
    for (int i = n; i > 0; --i)
    {
        cout << s;
    }
    cout << '\n';
    
    print_str(n - 2, padding + 1, s);
    if (n == 1)
    {
        return;
    }

    for (int i = 0; i < padding; ++i)
    {
        cout << " ";
    }
    for (int i = n; i > 0; --i)
    {
        cout << s;
    }
    cout << '\n';
}

// 1 + 2 * 3 + 2 * 5 + 2 * 7...
int main()
{
    int n;
    string s;
    auto sum = 1;
    cin >> n >> s;
    int i = 3;
    for (; ; ++i, ++i)
    {
        sum += 2 * i;
        if (sum > n)
        {
            sum -= 2 * i;
            i -= 2;
            break;
        }
    }

    print_str(i, 0, s);

    cout << n - sum << '\n';
    return 0;
}