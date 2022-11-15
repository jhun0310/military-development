/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 11. 13.
Baekjoon 9020th quiz.

~conception~
골드바흐 문제.
방법1.
1. 에라토스테네스의 체로 2~10000까지의 소수 집합 구해두기.
2. 주어진 수보다 작은 소수들끼리 더하며 주어진 수가 나올 때까지 연산.

~limit~

~data structure~

~Work Step~
1. 정수 입력받기
2. 에라토스테네스의 체 사용, 배열에 저장.
3. 두 소수끼리 더하며 주어진 수와 비교.

~추가적 내용 정리~

*/

#include <stdio.h>
#include <stdlib.h>

int *prime;
int prime_n = 0;

void prime_sieve(void)
{
    int *n = (int *)calloc(sizeof(int), 10000); //0으로 초기화됨. 0이면 prime, 1이면 none-prime
    n[0] = 1;
    
    for(int i = 1; i < 10000; i++)
    {
        if(n[i] == 1)
        {
            continue;
        }
        else
        {
            for(int j = 2; (j * (i + 1)) <= 10000; j++)
            {
                n[j * (i + 1) - 1] = 1;
            }
            prime_n++;
        }
    }

    int prime_index = 0;
    prime = (int *)malloc(sizeof(int) * prime_n);

    for(int i = 1; i < 10000; i++)
    {
        if(n[i] == 0)
        {
            prime[prime_index++] = (i + 1);
        }
    }

    free(n);

    return;
}

void gold_output(int num, int *a, int *b)
{
    for(int i = 0; prime[i] <= (num / 2); i++)
    {
        for(int j = 0; prime[j] <= num; j++)
        {
            if((prime[i] + prime[j]) == num)
            {
                *a = prime[i];
                *b = prime[j];
            }
        }
    }

    return;
}

int main(void)
{
    prime_sieve();

    int n, num, a, b;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        gold_output(num, &a, &b);
        printf("%d %d\n", a, b);
    }

    return 0;
}