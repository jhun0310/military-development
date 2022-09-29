/*
기본 연산자 관련 연습.
*/

#include <stdio.h>

int main(void)
{
    int a;
    a = (getchar() - 48);

    printf("%c\n", (a ? '1' : '0'));

    return 0;
}