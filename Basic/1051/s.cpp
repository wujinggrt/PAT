#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double r1;
    double p1;
    double r2;
    double p2;
    cin >> r1 >> p1 >> r2 >> p2;
    double a = (r1 * r2) * cos(p1 + p2);
    double b = (r1 * r2) * sin(p1 + p2);
    if(abs(a) < 0.01){
        a = 0;
    }
    if(abs(b) < 0.01){
        b = 0;
    }
    if(b < 0){
        printf("%.2lf-%.2lfi", a, abs(b));
    }
    else{
        printf("%.2lf+%.2lfi", a, b);
    }
    return 0;
}