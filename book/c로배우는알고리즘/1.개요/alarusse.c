/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* A la russe algorithm.
*/

#include <stdio.h>

int a_la_russe(unsigned int first, unsigned int second)
{
    unsigned int third = 0;

    if((first % 2) == 1)
    {
        third += second;
    }

    while(first != 1)
    {
        first = first >> 1;
        second = second << 1;

        if((first % 2) == 1)
        {
            third += second;
        }
    }

    return third;
}

int main(void)
{
    int a, b;

    scanf("%d%d", &a, &b);

    printf("%d", a_la_russe((unsigned int)a, (unsigned int)b));

    return 0;
}