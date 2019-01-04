#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 100;
    int *p = &i;
    printf("%p\n", p);
    return 0;
}