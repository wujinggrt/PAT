#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long N;
    long long p;
    cin >> N >> p;
    vector<long long> vec;
    vec.reserve(N);
    for (long long i = 0; i < N; ++i)
    {
        long long tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    int ans = 1;
    bool break_flag = false;
    for(int j = 0; j < N; j++)
    {
        for(int i = j + ans; i < N; i++) /*这里的ans只是一个区间大小*/
        {
            /*
            对于当前的vec[i]，它能够对应的最大限度的vec[i]是多少，
            内部的循环就是每次执行到这不，然后++j，j的下一个，又找到最大的。
            j的区间为j+ans，所以 i-j肯定是ans，一开始。
            之后随着i增大而增大。
            */
            /* 
             M <= m * p, 
             vec[i]是当前 j..i 段， 当前区间最大值，并不是所有
             需要一直更新到最后一个位子，因为最大值还是vec[N - 1]
             当前最大值不满足情况，意味着当前最大值vec[i]大了
             那么break这个循环，延伸到后面的区间，找到更大的值
             比如一个极端的情况，在ans只在这个循环一次更新到ans = N - 1,
             那么外部的循环就几乎只执行++j，不执行这个for了
             */
            if(vec[i] <= vec[j] * p)
            {
                    ans = i - j + 1;
            }
            else
            {
                break;
            }
        }
    }
/*
一开始想到的是使用优先队列，但是效率问题没AC
后来的逻辑是 每次开始查找的范围随着ans的值增大不断缩减
像quicksort的partition
换言之 就是我经过一次遍历后 已经确定了较大的ans值 在下一次遍历的时候我就从 j+ans 值位置开始 
类似于KMP的一步跨越尽可能多的元素个数
*/
    // version 1. Unefficient.
    // priority_queue<long long, std::vector<int>, std::less<int>> pq(vec.begin(), vec.end());
    // while (!pq.empty())
    // {
    //     if (maximum <= pq.top() * p)
    //     {
    //         ++count;
    //         pq.pop();
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
    printf("%d\n", ans);
    return 0;
}