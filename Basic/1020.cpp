#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

struct Goods
{
    double amounts;
    double prices;
};

int main()
{
    int n, d;
    cin >> n >> d;
    vector<Goods> goods(n, Goods());
    for (int i = 0; i < n; ++i)
    {
        double amounts;
        cin >> amounts;
        goods[i].amounts = amounts;
    }
    for (int i = 0; i < n; ++i)
    {
        double prices;
        cin >> prices;
        goods[i].prices = prices;
    }
    sort(goods.begin(), goods.end(), [] (auto l, auto r) { return (l.prices / l.amounts) > (r.prices / r.amounts);});
    double total = 0.;
    for (const auto &e: goods)
    {
        if (d <= 0)
        {
            break;
        }
        if (d >= e.amounts)
        {
            total += e.prices;
            d -= e.amounts;
        }
        else if (d > 0 && d < e.amounts)
        {
            total += e.prices / e.amounts * d;
            d = 0;
        }
    }
    printf("%.2f", total);
    return 0;
}