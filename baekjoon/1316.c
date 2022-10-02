/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 02.
* Baekjoon 1316th question.
*/

#include <stdio.h>

int main(void)
{
    int g_w_num, loop, cal_go = 1;
    int alp[26] = { 0 }; //0 -> none-exist, 1 -> exist
    char tmp, last_alp = 0;

    scanf("%d", &loop);
    g_w_num = loop;

    getchar();

    for(int i = 0; i < loop; i++)
    {
        //calculate
        while((tmp = getchar()) != '\n')
        {
            if(cal_go == 0)
            {
                continue;
            }

            if(last_alp == 0)
            {
                last_alp = tmp;
                alp[tmp - 97] = 1;

                continue;
            }

            if((tmp != last_alp) && (alp[tmp - 97] == 1))
            {
                g_w_num--;
                cal_go = 0;
            }
            else if((tmp != last_alp) && (alp[tmp - 97] == 0))
            {
                alp[tmp - 97] = 1;
                last_alp = tmp;
            }
        }

        //reset
        last_alp = 0;
        cal_go = 1;

        for(int j = 0; j < 26; j++)
        {
            alp[j] = 0;
        }   
    }

    printf("%d", g_w_num);

    return 0;
}