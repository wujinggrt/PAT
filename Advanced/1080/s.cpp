#include <cstdio>
#include <iostream>
using namespace std;

struct A {
    A& operator=(const A& other) = delete;
};

int main() {
    int n, m, k;
    // cin >> n >> m >> k;
    A a;
    A b;
    a = b;
}