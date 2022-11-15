/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 11. 15.
Baekjoon 10870th quiz.
*/

#include <stdio.h>

int pib(int n)
{
    if(n == 0) return 0;
    else if(n == 1) return 1;

    return (pib(n - 1) + pib(n - 2));
}

int main(void)
{
    int n;
    scanf("%d", &n);

    printf("%d", pib(n));

    return 0;
}