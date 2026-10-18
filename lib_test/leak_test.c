#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int add(int a, int b);
int multiply(int a, int b);

void sub(void)
{
    int i;                          /* 초기화되지 않은 변수 */
    int *ptr;

    ptr = malloc(MAX * sizeof(int));
    ptr[0] = add(10, 5);
    ptr[MAX] = multiply(10, 5);     /* 불법적인 메모리 쓰기 (범위 초과) */

    if (i > 0)                      /* 초기화되지 않은 값 사용 */
        printf("i is positive\n");

    ptr = 0;                        /* free 없이 포인터를 잃음 → 메모리 누수 */
}

int main(void)
{
    sub();
    return 0;
}
