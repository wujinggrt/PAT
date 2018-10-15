#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Student
{
    int no;
    int morals;
    int abilities;
};

/*
德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才 总分 从高到低排序；
才分不到但德分到线的一类考生属于“德胜才”，也按 总分排序 ，但排在第一类考生之后；
德才分均低于 H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按 总分 排序，但排在第二类考生之后；
其他达到最低线 L 的考生也按 总分排序，但排在第三类考生之后。

12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
*/

int main()
{
    int n, L, H, cnt = 0;
    cin >> n >> L >> H;
    vector<Student> greaters, moral_greaters, moral_passers, passers;
    greaters.reserve(n);
    moral_greaters.reserve(n);
    moral_passers.reserve(n);
    passers.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int no, morals, abilities;
        cin >> no >> morals >> abilities;
        if (morals < L || abilities < L)
        {
            continue;
        }
        else if (morals >= H && abilities >= H)
        {
            greaters.push_back(Student{no, morals, abilities});
        }
        else if (morals >= H && abilities < H)
        {
            moral_greaters.push_back(Student{no, morals, abilities});
        }
        else if (morals >= abilities)
        {
            moral_passers.push_back(Student{no, morals, abilities});
        }
        else
        {
            passers.push_back(Student{no, morals, abilities});
        }
        ++cnt;
    }

    cout << cnt << "\n";
    auto cmp = [](const Student &l, const Student &r){
        if ((l.morals + l.abilities) == (r.morals + r.abilities))
        {
            if (l.morals == r.morals)
            {
                return l.no < r.no;
            }
            else
            {
                return l.morals > r.morals;
            }
        }
        else
        {
            return (l.morals + l.abilities) > (r.morals + r.abilities);
        }
    };
    sort(greaters.begin(), greaters.end(), cmp);
    sort(moral_greaters.begin(), moral_greaters.end(), cmp);
    sort(moral_passers.begin(), moral_passers.end(), cmp);
    sort(passers.begin(), passers.end(), cmp);
#define PRINT(VEC)     \
    for (const auto &e: VEC) \
    { \
        printf("%.8d ", e.no); \
        cout << e.morals << " " << e.abilities << '\n'; \
    }
    
    PRINT(greaters);
    PRINT(moral_greaters);
    PRINT(moral_passers);
    PRINT(passers);
    
    return 0;
}