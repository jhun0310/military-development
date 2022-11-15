/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 11. 15.
Baekjoon 3009th quiz.
*/

#include <stdio.h>

void comp3n(int a, int b, int c)
{
    (a == b) ? (printf("%d ", c)) : ((a == c) ? (printf("%d ", b)) : (printf("%d ", a)));

    return;
}

int main(void)
{
    int d[3][2];

    for(int i = 0; i < 3; i++)
    {
        scanf("%d%d", &d[i][0], &d[i][1]);
    }

    for(int i = 0; i < 2; i++)
    {
        comp3n(d[0][i], d[1][i], d[2][i]);
    }

    return 0;
}