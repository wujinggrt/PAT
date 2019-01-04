#include <iostream>
#include <string>
using namespace std;

int main()
{
    string A, B;
    char DA, DB;
    cin >> A >> DA >> B >> DB;
    int cnt_DA = 0;
    int cnt_DB = 0;
    for (const auto &c: A)
    {
        if (c == DA)
        {
            ++cnt_DA;
        }
    }
    for (const auto &c: B)
    {
        if (c == DB)
        {
            ++cnt_DB;
        }
    }
    int da = (cnt_DA ? DA - '0' : 0);
    int db = (cnt_DB ? DB - '0' : 0);
    while (--cnt_DA > 0)
    {
        da = da * 10 + (DA - '0');
    }
    while (--cnt_DB > 0)
    {
        db = db * 10 + (DB - '0');
    }
    cout << (da + db);
    return 0;
}