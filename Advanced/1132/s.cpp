#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
    //freopen("i.dat", "r", stdin);
    int n;
    cin >> n;
    for (; n != 0; --n) {
        string z;
        cin >> z;
        int a;
        int b;
        int num;
        sscanf(z.substr(0, z.size() / 2).c_str(), "%d", &a);
        sscanf(z.substr(z.size() / 2).c_str(), "%d", &b);
        sscanf(z.c_str(), "%d", &num);
        cout << ((a * b != 0) && num % (a * b) == 0 ? "Yes" : "No") << endl;
    }
}
