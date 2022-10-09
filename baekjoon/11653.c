/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 04.
* Baekjoon 11653th question. (using recursion.)
*/

#include <stdio.h>

void pr_factor(int num)
{
    if(num == 1)
    {
        return;
    }

    //caluculate
    for(int i = 2; i <= num; i++)
    {
        if((num % i) == 0)
        {
            printf("%d\n", i);
            pr_factor(num / i);
            break;
        }
    }
}

int main(void)
{
    int N;

    scanf("%d", &N);

    pr_factor(N);

    return 0;
}