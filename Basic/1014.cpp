#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

bool check_weekday(char c)
{
    return (c >= 'A' && c <= 'G');
}

bool check_time(char c)
{
    return (c >= '0' && c <= '9' || c >= 'A' && c <= 'N');
}

void parse()
{
    string date1;
    string date2;
    string time1;
    string time2;
    cin >> date1 >> date2 >> time1 >> time2;
    unsigned weekday = 0;
    char time;
    bool weekday_flag = true;
    for (int i = 0; i < date1.size() && i < date2.size(); ++i)
    {
        if (weekday_flag && !check_weekday(date1[i]))
        {
            continue;
        }
        else if (!check_time(date1[i]))
        {
            continue;
        }
        if (weekday_flag)
        {
            if (date1[i] == date2[i])
            {
                    weekday = date1[i] - 'A';
                    weekday_flag = false;
                    continue;
            }
        }
        else
        {
            if (date1[i] == date2[i])
            {
                time = date1[i];
                break;
            }
            
        }
    }

    std::unordered_map<unsigned, const string> week{{0, "MON"},
        {1, "TUE"},
        {2, "WED"},
        {3, "THU"},
        {4, "FRI"},
        {5, "SAT"},
        {6, "SUN"}
        };
    cout << week[weekday] << " ";
    if (time >= '0' && time <='9')
    {
        cout << "0" << time << ":";
    }
    else
    {
        cout << ((time - 'A') + 10) << ":";
    }

    for (int i = 0; i < time1.size() && i < time2.size(); ++i)
    {
        if (isalpha(time1[i]))
        {
            if (time1[i] == time2[i])
            {
                cout << (i < 10 ? "0" : "") << i;
                return;
            }
        }
    }
}

int main()
{
    parse();
    return 0;
}