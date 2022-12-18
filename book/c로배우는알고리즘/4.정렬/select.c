/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 12. 11. , 22. 12. 17.
Selection sort algorithm. 'c로 배우는 알고리즘 1' p.321.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//선택 정렬으로 정수 배열을 오름차순으로 정렬하는 함수.
void selection_sort(int a[], int size)
{
    int min, tmp;

    for(int i = 0; i < size; i++)
    {
        min = i;
        for(int j = (i + 1); j < size; j++)
        {
            if(a[min] > a[j])
            {
                min = j;
            }
        }
        
        if(min != i)
        {
            tmp = a[min];
            a[min] = a[i];
            a[i] = tmp;
        }
    }

    return;
}

//d1이 d2보다 크면 교환
int cmp_int(void *d1, void *d2)
{
    return (*((int *)d1) - *((int *)d2));
}

/*
선택 정렬으로 배열을 오름차순으로 정렬하는 일반형 함수.
ele_num->요소 개수
ele_size->요소 크기
*/
void selection_sort_jen(void *a, int ele_num, int ele_size, int (*cmp)(void *d1, void *d2))
{
    int min;
    void *tmp = malloc(ele_size);

    for(int i = 0; i < ele_num; i++)
    {
        min = i;
        for(int j = (i + 1); j < ele_num; j++)
        {
            if(cmp((char *)a + (ele_size * min), (char *)a + (ele_size * j)) > 0) //a[min] > a[j]
            {
                min = j;
            }
        }
        
        if(min != i)
        {
            //a[min] <-> a[i]
            memcpy(tmp, (char *)a + (ele_size * min), ele_size);
            memcpy((char *)a + (ele_size * min), (char *)a + (ele_size * i), ele_size);
            memcpy((char *)a + (ele_size * i), tmp, ele_size);
        }
    }

    return;
}

int main(void)
{
    int d[] = {0, 3, 2, 1, 4, 9, 203, 21, 523, 54, -1, -5};
    int d2[] = {0, 3, 2, 1, 4, 9, 203, 21, 523, 54, -1, -5};

    selection_sort(d, sizeof(d) / sizeof(int));
    selection_sort_jen(d2, sizeof(d2) / sizeof(int), sizeof(int), cmp_int);

    //result
    for(int i = 0; i < (sizeof(d) / sizeof(int)); i++)
    {
        printf("%d ", d[i]);
    }
    printf("\n");
    for(int i = 0; i < (sizeof(d) / sizeof(int)); i++)
    {
        printf("%d ", d2[i]);
    }
    printf("\n");

    return 0;
}