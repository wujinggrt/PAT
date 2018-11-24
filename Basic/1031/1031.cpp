#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> weight{7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

string m{"10X98765432"};

auto total = accumulate(
    weight.begin(), 
    weight.end(), 
    0, 
    [] (auto &l, const auto &r)
        {
            return l + r;
        }
    );

int to_i(const char &c)
{
    return c - '0' < 10 ? c - '0' : 10;
}

bool filter(const string &id)
{
    int sum = 0.;
    bool invalid = false;
    for (int i = 0; i < 17; ++i)
    {
        auto n = to_i(id[i]);
        if (n == 10)
        {
            invalid = true;
            break;
        }
        sum += n * weight[i];
    }
    sum %= 11;
    if(invalid || m[sum] != id[17])
    {
        cout << id << '\n';
        return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    bool is_all_pass = true;
    for (int i = 0; i < n; ++i)
    {
        string id;
        cin >> id;
        auto flag = filter(id);
        if (!flag)
        {
            is_all_pass = false;
        }
    }
    if (is_all_pass)
    {
        cout << "All passed\n";
    }
    return 0;
}