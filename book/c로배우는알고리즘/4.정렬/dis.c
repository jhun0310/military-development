/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 12. 19.
Distribution counting algorithm. 'c로 배우는 알고리즘 1' p.345.

~추가적 내용 정리~
*/

#include <stdio.h>
#include <stdlib.h>

/*
분포수세기로 1~5로만 구성된 정수 배열을 오름차순으로 정렬하는 함수.
class는 도수 분포에서의 계급 수를 의미함.
*/
void distribution_count(int a[], int size, int class)
{
    int *b = (int *)malloc(sizeof(int) * size);
    int *cnt = (int *)malloc(sizeof(int) * class);

    for(int i = 0; i < class; i++) //초기화
    {
        cnt[i] = 0;
    }
    for(int i = 0; i < size; i++) //도수 계산
    {
        (cnt[a[i] - 1])++;
    }
    for(int i = 1; i < class; i++) //누적분포 계산
    {
        cnt[i] += cnt[i - 1];
    }
    for(int i = (size - 1); i >= 0; i--)
    {
        b[--(cnt[a[i] - 1])] = a[i];
    }
    for(int i = 0; i < size; i++) //복사
    {
        a[i] = b[i];
    }

    return;
}

int main(void)
{
    int d[] = {1, 3, 2, 2, 3, 1, 3, 2, 4, 2, 4, 3, 1, 2, 1, 2, 5, 1, 5, 3};

    distribution_count(d, sizeof(d) / sizeof(int), 5);
    for(int i = 0; i < (sizeof(d) / sizeof(int)); i++)
    {
        printf("%d ", d[i]);
    }
    printf("\n");

    return 0;
}