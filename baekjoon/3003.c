/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 09. 30.
* Baekjoon 3003th question.
*/

#include <stdio.h>

int main(void)
{
    int data[6];

    for(int i = 0; i < 6; i++)
    {
        scanf("%d", &(data[i]));
    }

    printf("%d %d %d %d %d %d", (1 - data[0]), (1 - data[1]), (2 - data[2]), (2 - data[3]), (2 - data[4]), (8 - data[5]));

    return 0;
}