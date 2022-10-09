/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 03.
* Baekjoon 2581th question.
* Can I save more time? (156ms now.)
*/

#include <stdio.h>

int prime_n_jdg(int num) //prime -> return 1, none-prime -> return 0
{
    int prime = 1;

    if(num == 1)
    {
        return 0;
    }

    for(int i = 2; i < num; i++)
    {
        if((num % i) == 0)
        {
            prime = 0;
        }
    }

    return prime;
}

int main(void)
{
    int M, N, sum = 0, min = 0;

    scanf("%d%d", &M, &N);

    for(int i = M; i <= N; i++)
    {
        if(prime_n_jdg(i) == 1)
        {
            sum += i;

            if(min == 0)
            {
                min = i;
            }
        }
    }

    if(sum == 0)
    {
        printf("-1");
    }
    else
    {
        printf("%d\n%d", sum, min);
    }

    return 0;
}