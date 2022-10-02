/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 02.
* Baekjoon 1712th question.
*/

#include <stdio.h>

int main(void)
{
    int num, crit = 0, add = 1, loop = 1;

    //input
    scanf("%d", &num);

    //calculate, output
    while(1)
    {
        if((crit < num) && ((crit + add) >= num))
        {
            break;
        }
        else
        {
            crit += add;
            loop++;
            
            if(add == 1)
            {
                add += 5;
            }
            else
            {
                add += 6;
            }
        }
    }

    printf("%d", loop);

    return 0;
}

/*
1~1     1
2~7     6
8~19    12
20~37   18
38~61   24

*/