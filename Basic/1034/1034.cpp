#include <cstdio>
using namespace std;

long gcd(long x, long y);
void print_fraction(long numerator, long denomitor);

int main()
{
    char ops[] = {'+', '-', '*', '/'};
    long numerator_l;
    long denomitor_l;
    long numerator_r;
    long denomitor_r;
    scanf("%ld/%ld %ld/%ld", &numerator_l, &denomitor_l, &numerator_r, &denomitor_r);

    for (int i = 0; i < 4; ++i)
    {
        print_fraction(numerator_l, denomitor_l);
        printf(" %c ", ops[i]);
        print_fraction(numerator_r, denomitor_r);
        printf(" = ");
        switch (ops[i])
        {
            case '+':
                print_fraction(numerator_l * denomitor_r + numerator_r * denomitor_l, denomitor_l * denomitor_r);
                break;
            case '-':
                print_fraction(numerator_l * denomitor_r - numerator_r * denomitor_l, denomitor_l * denomitor_r);
                break;
            case '*':
                print_fraction(numerator_l * numerator_r, denomitor_l * denomitor_r);
                break;
            case '/':
                print_fraction(numerator_l * denomitor_r, numerator_r * denomitor_l);
                break;            
        }
        printf("\n");
    }
    return 0;
}

void print_fraction(long numerator, long denomitor)
{
    if (denomitor == 0)
    {
        printf("Inf");
        return;
    }
    // normalize the sign.
    int sign = 1;
    if (numerator < 0)
    {
        sign *= -1;
        numerator *= -1;
    }
    if (denomitor < 0)
    {
        sign *= -1;
        denomitor *= -1;
    }
    auto common_divisor = gcd(numerator, denomitor);
    numerator /= common_divisor;
    denomitor /= common_divisor;
    if (sign == -1)
    {
        printf("(-");
    }
    if (denomitor == 1)
    {
        printf("%ld", numerator);
    }
    else if (numerator > denomitor)
    {
        printf("%ld %ld/%ld", numerator / denomitor, numerator % denomitor, denomitor);
    }
    else
    {
        printf("%ld/%ld", numerator, denomitor);
    }
    if (sign == -1)
    {
        printf(")");
    }
}

long gcd(long x, long y)
{
    if (y == 0)
    {
        return 0;
    }
    if (x == 0)
    {
        return y;
    }
    long ret = x;
    while(ret != 0)
    {
        ret = x % y;
        x = y;
        y = ret;
    }
    return x;
}