#include <iostream>
#include <string>
#include <cstdio>
#include <unordered_set>
using namespace std;

bool is_upper(const char &c)
{
    return c >= 'A' && c <= 'Z';
}

bool is_lower(const char &c)
{
    return c >= 'a' && c <= 'z';
}

bool is_num(const char &c)
{
    return c >= '0' && c <= '9';
}

bool is_space(const char &c)
{
    return c == '_';
}

bool is_shift(const char &c)
{
    return c == '+';
}

char to_upper_or_stay(const char &c)
{
    if (is_lower(c))
    {
        return c - ('a' - 'A');
    }
    else
    {
        return c;
    }
}

int main()
{
    string broken;
    string input;
    cin >> broken >> input;
    unordered_set<char> broken_set;

    bool shift_broken = false;

    for (const auto &c: broken)
    {
        if (is_shift(c))
        {
            shift_broken = true;
        }
        else
        {
            broken_set.insert(c);
        }
    }
    int outputed = 0;
    for (const auto &c: input)
    {
        if (shift_broken && is_upper(c))
        {
            continue;
        }
        if (broken_set.find(to_upper_or_stay(c)) != broken_set.cend())
        {
            continue;
        }
        cout << c;
        ++outputed;
    }
    if (outputed == 0)
    {
        cout << '\n';
    }

    return 0;
}