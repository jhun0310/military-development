/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 12. 18.
Shell sort algorithm. 'c로 배우는 알고리즘 1' p.345.

~추가적 내용 정리~
*/

#include <stdio.h>

/*
정수의 오름차순 정렬.
*/
void shell_sort(int a[], int size)
{
   int tmp, k;

    for(int h = (size / 2); h > 0; h /= 2)
    {
        for(int i = 0; i < h; i++)
        {
            for(int j = (h + i); j < size; j += h)
            {
                tmp = a[j];
                for(k = (j - h); k >= 0; k -= h)
                {
                    if(a[k] > tmp)
                    {
                        a[k + h] = a[k];
                    }
                    else
                    {
                        break;
                    }
                }
                a[k + h] = tmp;
            }
        }
    }

    return;
}

int main(void)
{
    int d[] = {0, 3, 2, 1, 4, 9, 203, 21, 523, 54, -1, -5};

    shell_sort(d, sizeof(d) / sizeof(int));
    for(int i = 0; i < (sizeof(d) / sizeof(int)); i++)
    {
        printf("%d ", d[i]);
    }
    printf("\n");

    return 0;
}