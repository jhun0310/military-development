/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 03.
* Baekjoon 1978th question.
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
    int loop, tmp, prime = 0;

    scanf("%d", &loop);

    for(int i = 0; i < loop; i++)
    {
        scanf("%d", &tmp);

        prime += (prime_n_jdg(tmp) ? 1 : 0);
    }

    printf("%d", prime);

    return 0;
}