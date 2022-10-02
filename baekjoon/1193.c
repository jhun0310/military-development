/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 02.
* Baekjoon 1712th question.
*/

#include <stdio.h>

int main(void)
{
    int num, son = 1, mom = 1;
    int chart_dir = 0; //0 -> right upper, 1 -> left lower

    //input
    scanf("%d", &num);

    //calculate
    for(int i = 1; i < num; i++)
    {
        if(chart_dir == 0)
        {
            if(son == 1)
            {
                mom++;
                chart_dir = 1;
            }
            else
            {
                mom++;
                son--;
            }
        }
        else //if(chart_dir == 1)
        {
            if(mom == 1)
            {
                son++;
                chart_dir = 0;
            }
            else
            {
                son++;
                mom--;
            }
        }
    }


    //output
    printf("%d/%d", son, mom);

    return 0;
}
