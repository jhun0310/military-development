#include <stdio.h>
#include <stdlib.h>

#define A 3
#define B 2

int main(void)
{
    char a[A][B] = {1, 2, 3, 4, 5, 6};

    for(int i = 0; i < A; i++)
    {
        for(int j = 0; j < B; j++)
        {
            printf("%d\n", a[i][j]);
        }
    }

    return 0;
}