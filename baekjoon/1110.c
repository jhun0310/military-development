/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 01.
* Baekjoon 1110th question.
*/

#include <stdio.h>

int main(void)
{
    int ori_num, num, cycle = 0;

    scanf("%d", &ori_num);
    num = ori_num;

    do
    {
        cycle++;

        if(num >= 10)
        {
            num = (((num % 10) * 10) + (((num / 10) + (num % 10)) % 10));
        }
        else //if(num < 10)
        {
            num = ((num * 10) + num);
        }
    }while(num != ori_num);

    printf("%d", cycle);

    return 0;
}