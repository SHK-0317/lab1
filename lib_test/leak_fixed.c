#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int add(int a, int b);
int multiply(int a, int b);

void sub(void)
{
    int i = 0;                      /* 초기화 */
    int *ptr;

    ptr = malloc(MAX * sizeof(int));
    ptr[0] = add(10, 5);
    ptr[MAX - 1] = multiply(10, 5); /* 범위 안으로 수정 */

    if (i > 0)
        printf("i is positive\n");

    free(ptr);                      /* 해제 */
}

int main(void)
{
    sub();
    return 0;
}
