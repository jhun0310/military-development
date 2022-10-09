/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 04.
* Baekjoon 11653th question 2nd answer. (using loop.)
* Can I shorten the time? (It's 28ms now.)
*/

#include <stdio.h>

int main(void)
{
    int N;

    scanf("%d", &N);

    while(1)
    {
        if(N == 1)
        {
            break;
        }

        //caluculate
        for(int i = 2; i <= N; i++)
        {
            if((N % i) == 0)
            {
                printf("%d\n", i);
                N = (N / i);
                break;
            }
        }   
    }

    return 0;
}