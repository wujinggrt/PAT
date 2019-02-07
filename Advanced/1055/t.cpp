#include <cstring>
#include <iostream>
using namespace std;

int main() {
    char s[5] = {"Hell"};
    char b[5];
    strcpy(b, s);
    cout << b << "\n";
}