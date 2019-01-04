#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct People
{
    string name;
    string birth;
};

int main()
{
    int n;
    cin >> n;
    int count = 0;
    vector<People> vec;
    vec.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        People p;
        cin >> p.name >> p.birth;
        if (p.birth < "1814/09/06" || p.birth > "2014/09/06")
        {
            ++count;
            continue;
        }
        vec.push_back(p);
    }
    sort(vec.begin(), vec.end(), [](auto l, auto r) { return l.birth < r.birth;});
    if (!vec.empty())
    {
        printf("%lu %s %s\n", vec.size(), vec.front().name.c_str(), vec.back().name.c_str());
    }
    else
    {
        printf("0\n");
    }    
    return 0;
}