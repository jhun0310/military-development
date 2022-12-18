/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 12. 18.
Insertion sort algorithm. 'c로 배우는 알고리즘 1' p.329.

~추가적 내용 정리~
*/

#include <stdio.h>

/*
정수의 오름차순 정렬.
*/
void insertion_sort(int a[], int size)
{
    int tmp, j;

    for(int i = 1; i < size; i++)
    {
        tmp = a[i];
        for(j = (i - 1); j >= 0; j--)
        {
            if(a[j] > tmp)
            {
                a[j + 1] = a[j];
            }
            else
            {
                break;
            }
        }
        a[j + 1] = tmp;
    }

    return;
}

int main(void)
{
    int d[] = {0, 3, 2, 1, 4, 9, 203, 21, 523, 54, -1, -5};

    insertion_sort(d, sizeof(d) / sizeof(int));
    for(int i = 0; i < (sizeof(d) / sizeof(int)); i++)
    {
        printf("%d ", d[i]);
    }
    printf("\n");

    return 0;
}