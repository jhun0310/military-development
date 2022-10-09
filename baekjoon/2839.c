/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 03.
* Baekjoon 2839th question.
*/

#include <stdio.h>

int main(void)
{
    int N, bag_num, tmp_num;

    scanf("%d", &N);

    bag_num = ((N - 1) / 5) + 1;

    while(1)
    {
        tmp_num = (bag_num * 5);

        if((bag_num * 3) > N)
        {
            printf("-1");

            return 0;
        }

        for(int i = 0; i < (bag_num + 1); i++)
        {
            if(tmp_num == N)
            {   
                printf("%d", bag_num);

                return 0;
            }
            else
            {
                tmp_num -= 2;
            }
        }

        bag_num++;
    }
}

/*
14  





*/