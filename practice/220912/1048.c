/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* This program prints a decimal number as a bit.
*/

#include <stdio.h>

static void dec_to_bin_print(int num)
{
    printf("bit : ");

    int size = (((int)sizeof(int)) * 8);
    unsigned int mask = (1 << (size - 1));

    for(int i = 0; i < size; i++)
    {
        printf("%d", (num & mask) ? 1 : 0);

        mask = mask >> 1;
    }

    printf("  \n");

    return;
}

int main(void)
{
    int dec_num;

    while(1)
    {
        printf("Enter a decimal number. -> ");
        scanf("%d", &dec_num);

        dec_to_bin_print(dec_num);
    }

    return 0;
}