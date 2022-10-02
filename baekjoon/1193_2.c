/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 02.
* Baekjoon 1712th question 2nd answer.
*/

#include <stdio.h>

int main(void)
{
    int num, loop = 1;
    int chart_dir = 0; //0 -> right upper, 1 -> left lower.

    //input
    scanf("%d", &num);

    //calculate
    while((num - loop) > 0) //num is remaining value of the original number.
    {
        num -= loop;
        loop++;
    }

    //output
    if((loop % 2) == 0) //even.
    {
        printf("%d/%d", num, (loop - num + 1));
    }
    else //if((loop % 2) == 1), odd.
    {
        printf("%d/%d", (loop - num + 1), num);
    }

    return 0;
}
