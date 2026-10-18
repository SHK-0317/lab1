#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);

int main(void)
{
    long sum = 0;
    double d = 0;
    int i;

    for (i = 0; i < 100000000; i++) {
        sum += add(i, 1);
        sum -= subtract(i, 1);
        sum += multiply(i, 2) % 7;
        d   += divide(i, 3);
    }
    printf("sum=%ld d=%.2f\n", sum, d);
    return 0;
}
