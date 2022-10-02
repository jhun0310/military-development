/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 02.
* Baekjoon 1712th question.
*/

#include <stdio.h>

int main(void)
{
    int a, b, c;

    //input
    scanf("%d%d%d", &a, &b, &c);

    //calculate, output
    if(b >= c)
    {
        printf("-1");

        return 0;
    }

    printf("%d", ((a / (c - b)) + 1));

    return 0;
}