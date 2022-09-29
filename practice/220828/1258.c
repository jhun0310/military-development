//포인터 연습

#include <stdio.h>

void chg_num(int *, int *);

int main(void)
{
    int a, b;
    scanf("%d%d", &a, &b);

    chg_num(&a, &b);

    printf("a : %d, b : %d\n", a, b);

    return 0;
}

void chg_num(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;

    return;
}