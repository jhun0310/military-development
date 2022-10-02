/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 02.
* Baekjoon 2869th question.
*/

#include <stdio.h>

int main(void)
{
    int a, b, v, fin_date = 0, last_leng;

    //input
    scanf("%d%d%d", &a, &b, &v);

    //calculate
    fin_date = ((v - a) / (a - b)); //date
    last_leng = (fin_date * (a - b)); //length

    while(1)
    {
        fin_date++;

        if((last_leng + a) >= v)
        {
            break;
        }
        else
        {
            last_leng += (a - b);
        }
    }

    //output
    printf("%d", fin_date);

    return 0;
}

/*
(a - b) X A + a (min) > v

5 3 10

5 2 7 4 9 6 end


*/
