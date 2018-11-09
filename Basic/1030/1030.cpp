#include <functional>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    long N;
    long m;
    cin >> N >> m;
    vector<long> vec;
    vec.reserve(N);
    for (long i = 0; i < N; ++i)
    {
        long tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    long maximum = 0;
    for_each(vec.begin(), vec.end(), [&maximum](auto e) {
        if (e > maximum)
        {
            maximum = e;
        }
    });
    priority_queue<long> pq(vec.begin(), vec.end());
    long count = 0;
    while (!pq.empty())
    {
        if (maximum <= pq.top() * m)
        {
            ++count;
            pq.pop();
        }
        else
        {
            break;
        }
    }
    printf("%ld\n", count);
    return 0;
}