/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 01.
* Baekjoon 10809th question.
*/

#include <stdio.h>

int main(void)
{
    char alpha[26] = { 0 }; //0 -> -1, 1 -> 0, ...
    char tmp;
    int loc = 0;

    while((tmp = getchar()) != '\n')
    {
        loc++;

        if(alpha[tmp - 97] == 0)
        {
            alpha[tmp - 97] = loc;
        }
    }

    for(int i = 0; i < 26; i++)
    {
        printf("%d ", (alpha[i] - 1));
    }

    return 0;
}