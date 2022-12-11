/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 12. 4.
Baekjoon 1037th quiz.
*/

#include <stdio.h>
#define SIZE    50

int d[SIZE] = {0};

void data_input(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &(d[i]));
    }

    return;
}

int max_min(int cal_type)
{
    int value;

    if(cal_type == 1) //maximum
    {
        value = 1;
        for(int i = 0; d[i] != 0; i++)
        {
            if(d[i] > value) value = d[i];
        }
    }
    else if(cal_type == 0) //minimum
    {
        value = d[0];
        for(int i = 0; d[i] != 0; i++)
        {
            if(d[i] < value) value = d[i];
        }
    }

    return value;
}

int main(void)
{
    data_input();
    printf("%d\n", (max_min(1) * max_min(0)));

    return 0;
}