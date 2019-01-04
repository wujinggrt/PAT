#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

static const char* en_set[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

bool flag = true;

void print_en(int n) {
    if (n > 10) {
        print_en(n / 10);
    }
    if (flag) {
        flag = false;
        printf("%s", en_set[n % 10]);
    } else {
        printf(" %s", en_set[n % 10]);
    }
}

int main() {
    char c;
    int sum = 0;
    while ((c = cin.get()) != '\n') {
        sum += c - '0';
    }
    print_en(sum);
}