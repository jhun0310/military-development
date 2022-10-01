/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 01.
* Baekjoon 4673th question.
*/

#include <stdio.h>

#define SIZE 10000

int num[SIZE] = { 0 }; //0 -> self number, 1 -> not self number / 0 ~ 9999

void d_cal(int n)
{
    if(n < 100)
    {
        n = (n + (n / 10) + (n % 10));
    }
    else if(n < 1000)
    {
        n = (n + (n / 100) + ((n / 10) % 10) + (n % 10));
    }
    else
    {
        n = (n + (n / 1000) + ((n / 100) % 10) + ((n / 10) % 10) + (n % 10));
    }

    if(n > SIZE)
    {
        return;
    }
    else
    {
        num[n - 1] = 1;
    }
}

int main(void)
{
    for(int i = 1; i < SIZE; i++)
    {
        d_cal(i);
    }

    for(int i = 0; i < SIZE; i++)
    {
        if(num[i] == 0)
        {
            printf("%d\n", (i + 1));
        }
    }

    return 0;
}