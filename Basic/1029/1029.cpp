#include <memory>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    string in;
    string out;
    cin >> in >> out;
    vector<char> order;
    unordered_map<char, int> m;

    auto upper_cast = [] (const char &c) -> char { return c <= 'z' && c >= 'a' ? c - 32 : c;};
    for (int i = 0, j = 0; i < in.size(); ++i)
    {
        if (in[i] != out[j])
        {
            m[upper_cast(in[i])]++;
            order.push_back(upper_cast(in[i]));
        }
        else
        {
            ++j;
        }
    }
    for_each(order.begin(), order.end(), [&m] (auto e) {
        auto p = &m[e];
        if (*p != 0)
        {
            cout << e;
            *p = 0;
        }
    });
    cout << "\n";
    return 0;
}