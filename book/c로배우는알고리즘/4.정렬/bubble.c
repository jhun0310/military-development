/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 12. 18.
Bubble sort algorithm. 'c로 배우는 알고리즘 1' p.338.

~추가적 내용 정리~
*/

#include <stdio.h>

/*
정수의 오름차순 정렬.
*/
void bubble_sort(int a[], int size)
{
    int tmp;

    for(int i = (size - 1); i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }

    return;
}

int main(void)
{
    int d[] = {0, 3, 2, 1, 4, 9, 203, 21, 523, 54, -1, -5};

    bubble_sort(d, sizeof(d) / sizeof(int));
    for(int i = 0; i < (sizeof(d) / sizeof(int)); i++)
    {
        printf("%d ", d[i]);
    }
    printf("\n");

    return 0;
}