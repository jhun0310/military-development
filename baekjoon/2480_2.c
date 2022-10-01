/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 01.
* Baekjoon 2480th question 2nd answer.
*/

#include <stdio.h>

int main(void)
{
    int num[4], print_num = 0, same = 0;

    scanf("%d%d%d", &num[0], &num[1], &num[2]);
    num[3] = num[0];

    for(int i = 0; i < 3; i++)
    {
        if(num[i] == num[i + 1])
        {
            same++;
            print_num = num[i];
        }
        else if(num[i] < num[i + 1])
        {
            if((same == 0) && (print_num < num[i + 1]))
            {
                print_num = num[i + 1];
            }
        }
        else //if(num[i] > num[i + 1])
        {
            if((same == 0) && (print_num < num[i]))
            {
                print_num = num[i];
            }
        }
    }

    if(same == 0)
    {
        printf("%d", (print_num * 100));
    }
    else if(same == 1)
    {
        printf("%d", (1000 + (print_num * 100)));
    }
    else //if(same == 3)
    {
        printf("%d", (10000 + (print_num * 1000)));
    }

    return 0;
}