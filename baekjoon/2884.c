/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 09. 30.
* Baekjoon 2884th question.
*/

#include <stdio.h>

int main(void)
{
    int hour, minute;
    scanf("%d%d", &hour, &minute);

    minute = minute - 45;

    if(minute < 0)
    {
        hour--;
        minute = minute + 60;

        if(hour < 0)
        {
            hour = hour + 24;
        }
    }
    
    printf("%d %d", hour, minute);

    return 0;
}