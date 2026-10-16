#include <stdio.h>

int add(int a, int b)      { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

double divide(int a, int b)
{
    if (b == 0)
        return 0;          /* 0으로 나누기 방지 */
    return (double)a / b;
}	
