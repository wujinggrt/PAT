#include <stack>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long A, B, D;
    cin >> A >> B >> D;
    long C = A + B;
    stack<int> s;
    if (C == 0 || D == 10)
    {
        cout << C;
    }
    else if (D != 1)
    {
        while (C)
        {
            s.push(C % D);
            C /= D;
        }
        // while (!s.empty() && !s.top())
        // {
        //     s.pop();
        // }
        while (!s.empty())
        {
            cout << s.top();
            s.pop();
        }
    }
    else
    {
        while (C--)
        {
            cout << 0;
        }
    }
    return 0;
}