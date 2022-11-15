/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 11. 15.
Baekjoon 2563th quiz.
*/

#include <stdio.h>

#define SIZE    100

int main(void)
{
    int a[SIZE][SIZE] = { 0 };
    int n, black = 0, n1, n2;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &n1, &n2);

        for(int j = n1; j < (n1 + 10); j++)
        {
            for(int k = n2; k < (n2 + 10); k++)
            {
                if(a[j][k] == 1)
                {
                    continue;
                }
                else
                {
                    a[j][k] = 1;
                    black++;
                }
            }
        }
    }

    printf("%d", black);

    return 0;
}
