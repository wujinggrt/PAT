#include <queue>
#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    map<int, int> num;
    for (int i = 0; i < 10; ++i)
    {
        int cnt = 0;
        cin >> cnt;
        num[i] = cnt;
    }
    queue<int> q;
    for (auto it = ++num.begin(); it != num.end(); ++it)
    {
        while (it->second)
        {
            q.push(it->first); 
            --it->second;
            while (num[0])
            {
               q.push(0);
               num[0]--;
            }
        }
    }
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }
    return 0;
}