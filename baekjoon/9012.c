/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 12. 4.
Baekjoon 9012th quiz.
*/

#include <stdio.h>
#define STR_SIZE    50

int brack_judge(char s[STR_SIZE]) //VPS->1, NONE_VPS->0
{
    int n = 0;
    for(int i = 0; s[i] != 0; i++)
    {
        if(s[i] == '(')
        {
            n++;
        }
        else if(s[i] == ')')
        {
            n--;
        }

        if(n < 0) return 0;
    }
    if(n == 0) return 1;
    else return 0;
}

int main(void)
{
    int n;
    char d[STR_SIZE];

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", d);
        printf("%s\n", (brack_judge(d)) ? "YES" : "NO");
    }

    return 0;
}