/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 04.
* Baekjoon 1929th question.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int M, N;
    int *data_ptr = NULL;
    
    scanf("%d%d", &M, &N);

    data_ptr = (int *)malloc(sizeof(int) * N); //1 -> non-prime, 0 -> prime. number N is in (N - 1).
    for(int i = 0; i < N; i++)
    {
        data_ptr[i] = 0;
    }

    data_ptr[0] = 1;
    for(int i = 2; i < N; i++) //sieve
    {
        if(data_ptr[i - 1] == 1)
        {
            continue;
        }
        else
        {
            for(int j = 2; (j * i) <= N; j++)
            {
                data_ptr[(j * i) - 1] = 1;
            }
        }
    }

    for(int i = M; i <= N; i++)
    {
        if(data_ptr[i - 1] == 0)
        {
            printf("%d\n", i);
        }
    }


    return 0;
}