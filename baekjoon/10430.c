/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 09. 30.
* Baekjoon 10430th question.
*/

#include <stdio.h>

int main(void)
{
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    printf("%d\n%d\n%d\n%d", (a+b)%c, ((a%c) + (b%c))%c, (a*b)%c, ((a%c) * (b%c))%c);

    return 0;
}