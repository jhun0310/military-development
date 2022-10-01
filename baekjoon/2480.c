/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 01.
* Baekjoon 2480th question.
*/

#include <stdio.h>

int main(void)
{
    int num[3]; 
    int same = 0;

    scanf("%d%d%d", &num[0], &num[1], &num[2]);

    if((num[0] == num[1]) || (num[1] == num[2]) || (num[0] == num[2])) //double
    {
        if((num[0] == num[1]) && (num[1] == num[2])) //triple
        {
            printf("%d", (10000 + (num[0] * 1000)));
        }
        else
        {
            if(num[0] == num[1])
            {
                printf("%d", (1000 + (num[0] * 100)));
            }
            else if(num[1] == num[2])
            {
                printf("%d", (1000 + (num[1] * 100)));
            }
            else if(num[0] == num[2])
            {
                printf("%d", (1000 + (num[0] * 100)));
            }
        }
    }
    else
    {
        if(num[0] >= num[1])
        {
            if(num[0] >= num[2])
            {
                printf("%d", (num[0] * 100));
            }
            else
            {
                printf("%d", (num[2] * 100));
            }
        }
        else
        {
            if(num[1] >= num[2])
            {
                printf("%d", (num[1] * 100));
            }
            else
            {
                printf("%d", (num[2] * 100));
            }
        }
    }

    return 0;
}