/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 01.
* Baekjoon 2941th question.
*/

#include <stdio.h>

int main(void)
{
    int minus = 0, length = 0;
    char tmp_wd[3] = { 0 };
    char tmp;

    while((tmp = getchar()) != '\n')
    {
        length++;

        tmp_wd[2] = tmp_wd[1];
        tmp_wd[1] = tmp_wd[0];
        tmp_wd[0] = tmp;

        if((tmp_wd[2] == 'd') && (tmp_wd[1] == 'z') && (tmp_wd[0] == '='))
        {
            minus += 2;
            continue;
        }
        if((tmp_wd[1] == 'c') && (tmp_wd[0] == '=')) (minus++);
        if((tmp_wd[1] == 'c') && (tmp_wd[0] == '-')) (minus++);
        if((tmp_wd[1] == 'd') && (tmp_wd[0] == '-')) (minus++);
        if((tmp_wd[1] == 'l') && (tmp_wd[0] == 'j')) (minus++);
        if((tmp_wd[1] == 'n') && (tmp_wd[0] == 'j')) (minus++);
        if((tmp_wd[1] == 's') && (tmp_wd[0] == '=')) (minus++);
        if((tmp_wd[1] == 'z') && (tmp_wd[0] == '=')) (minus++);
    }

    printf("%d", (length - minus));

    return 0;
}