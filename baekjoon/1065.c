/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 01.
* Baekjoon 1065th question.
*/

#include <stdio.h>

int han_num(int num)
{
    int count;

    if(num < 100)
    {
        return num;
    }
    else
    {
        count = 99;

        for(int i = 0; i <= 4; i++) //allowance
        {
            for(int j = 0; j < 10; j++) //smallest number
            {
                if((j + (i * 2)) < 10)
                {
                    if((((j * 100) + ((j + i) * 10) + (j + (i * 2))) <= num) && (j != 0))
                    {
                        count++;
                    }
                    
                    if((((j + (i * 2)) * 100 + ((j + i) * 10) + j) <= num) && (i != 0))
                    {
                        count++;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }

    return count;
}

int main(void)
{
    int num;

    scanf("%d", &num);

    printf("%d", han_num(num));

    return 0;
}