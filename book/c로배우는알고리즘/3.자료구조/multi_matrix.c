/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* 22. 10. 23.
* This program is a practice for array by multiplying matrix.
*/

#include <stdio.h>
#include <stdlib.h>

void matrix_input(int ***A, char *name, int order)
{
    *A = (int **)malloc(sizeof(int *) * order);
    for(int i = 0; i < order; i++)
    {
        (*A)[i] = (int *)malloc(sizeof(int) * order);
    }

    printf("%s의 성분 : \n", name);

    for(int i = 0; i < order; i++)
    {
        for(int j = 0; j < order; j++)
        {
            scanf("%d", (*A)[i] + j);
        }
    }

    return;
}

void matrix_multi(int **A, int **B, int ***C, int order)
{
    *C = (int **)malloc(sizeof(int *) * order);
    for(int i = 0; i < order; i++)
    {
        (*C)[i] = (int *)malloc(sizeof(int) * order);
    }

    for(int i = 0; i < order; i++)
    {
        for(int j = 0; j < order; j++)
        {
            (*C)[i][j] = 0;

            for(int k = 0; k < order; k++)
            {
                (*C)[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }

    return;
}

void matrix_output(int **A, int order)
{
    printf("\n");

    for(int i = 0; i < order; i++)
    {
        for(int j = 0; j < order; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    return;
}

int main(void)
{
    int **A, **B, **C;
    int order;

    //input
    printf("정방행렬의 차수 : ");
    scanf("%d", &order);

    matrix_input(&A, "A", order);
    matrix_input(&B, "B", order);

    //multiplying
    matrix_multi(A, B, &C, order);

    //output
    matrix_output(C, order);

    return 0;
}