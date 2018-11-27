#include <cstdio>
// #include <iostream>
// #include <vector>
// #include <string>
using namespace std;

// struct Real;
// void adjust_real(Real &v);
long gcd(long x, long y);

// struct Real
// {
//     Real(bool neg = false, long c = 0, long num = 0, long den = 0, bool inf = false)
//         : negative{neg}
//         , carry{c}
//         , numerator{num}
//         , denomitor{den}
//         , is_inf(inf)
//     {}

//     bool negative;
//     long carry;
//     // 分子
//     long numerator;
//     // 分母
//     long denomitor;
//     bool is_inf;
// };

// void print_real(const Real &c)
// {
//     if (c.negative)
//     {
//         cout << "(-";
//     }
//     if (c.carry != 0)
//     {
//         cout << c.carry;
//     }
//     if (c.numerator != 0)
//     {
//         cout << (c.carry != 0 ? " " : "") << c.numerator;
        
//         if (c.denomitor != 1)
//         {
//             cout << "/" << c.denomitor;
//         } 
//     }
//     else if (c.carry == 0)
//     {
//         cout << 0;
//     }
//     if (c.negative)
//     {
//         cout << ")";
//     }    
// }

// Real add_real(const Real &l, const Real &r)
// {
//     auto common_denomitor = l.denomitor * r.denomitor;
//     auto l_numerator = l.denomitor * l.carry + l.numerator;
//     auto r_numerator = r.denomitor * r.carry + r.numerator;
//     auto l_common_numerator = l_numerator * r.denomitor;
//     auto r_common_numerator = r_numerator * l.denomitor;

//     auto result = (l.negative ? -l_common_numerator : l_common_numerator) + 
//         (r.negative ? -r_common_numerator : r_common_numerator);

//     Real ret{false, 0, result, common_denomitor}; 
//     adjust_real(ret);
//     return ret;
// }

// Real minus_real(const Real &l, const Real &r)
// {
//     auto common_denomitor = l.denomitor * r.denomitor;
//     auto l_numerator = l.denomitor * l.carry + l.numerator;
//     auto r_numerator = r.denomitor * r.carry + r.numerator;
//     auto l_common_numerator = l_numerator * r.denomitor;
//     auto r_common_numerator = r_numerator * l.denomitor;

//     auto result = (l.negative ? -l_common_numerator : l_common_numerator) - 
//         (r.negative ? -r_common_numerator : r_common_numerator);

//     Real ret{false, 0, result, common_denomitor}; 
//     adjust_real(ret);
//     return ret;
// }

// Real time_real(const Real &l, const Real &r)
// {
//     auto result = ((l.carry == 0 ? 0 : l.carry) * l.denomitor + l.numerator) * 
//         ((r.carry == 0 ? 0 : r.carry) * r.denomitor + r.numerator);
//     result *= (l.negative * r.negative == 0 ? -1 : 1);
//     auto common_denomitor = l.denomitor * r.denomitor;
//     Real ret{false, 0, result, common_denomitor}; 
//     adjust_real(ret);
//     return ret;
// }

// Real divide_real(const Real &l, const Real &r)
// {
//     if (r.numerator == 0 && r.carry == 0)
//     {
//         return Real{0, 0, 0, 0, true};
//     }
//     auto inversed_numerator = r.denomitor;
//     auto inversed_denomitor = ((r.carry == 0 ? 0 : r.carry) * r.denomitor + r.numerator);
//     bool is_negative = (l.negative * r.negative == 0 ? true : false);
//     Real ret{is_negative, 0, l.numerator * inversed_numerator, l.denomitor * inversed_denomitor}; 
//     adjust_real(ret);
//     return ret;
// }



// void adjust_real(Real &v)
// {
//     if (v.numerator < 0)
//     {
//         v.negative = true;
//         v.numerator *= -1;
//     }
//     if (v.numerator >= v.denomitor)
//     {
//         v.carry = v.numerator / v.denomitor;
//         v.numerator %= v.denomitor;
//     }
//     auto common_divisor = gcd(v.numerator, v.denomitor);
//     v.numerator /= common_divisor;
//     v.denomitor /= common_divisor;
// }

// Real decode(const string &operand)
// {
//     Real ret{false, 0, 0, 0};
//     string numerator = "";
//     string denomitor = "";
//     bool former = true;
//     for (const auto &c: operand)
//     {
//         if (c == '-')
//         {
//             ret.negative = true;
//             continue;
//         }
//         if (c == '/')
//         {
//             former = false;
//             continue;
//         }
//         if (former)
//         {
//             ret.numerator = ret.numerator * 10 + (c - '0');
//         }
//         else
//         {
//             ret.denomitor = ret.denomitor * 10 + (c - '0');
//         }
//     }
//     adjust_real(ret);
//     return ret;
// }

// void run()
// {
//         string operand;
//     bool first_negative = false;
//     bool second_negative = false;
//     cin >> operand;
//     auto value1 = decode(operand);
//     cin >> operand;
//     auto value2 = decode(operand);

//     // add    
//     print_real(value1);
//     cout << " + ";
//     print_real(value2);
//     cout << " = ";
//     auto result = add_real(value1, value2);
//     print_real(result);
//     cout << '\n';

//     print_real(value1);
//     cout << " - ";
//     print_real(value2);
//     cout << " = ";
//     result = minus_real(value1, value2);
//     print_real(result);
//     cout << '\n';

//     print_real(value1);
//     cout << " * ";
//     print_real(value2);
//     cout << " = ";
//     result = time_real(value1, value2);
//     print_real(result);
//     cout << '\n';

//     print_real(value1);
//     cout << " / ";
//     print_real(value2);
//     cout << " = ";
//     result = divide_real(value1, value2);
//     if (result.is_inf)
//     {
//         cout << "Inf";
//     }
//     else
//     {
//         print_real(result);
//     }
//     cout << '\n';
// }

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
        print_fraction(numerator_l, denomitor_r);
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