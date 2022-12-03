/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 12. 2.
Baekjoon 1004th quiz.
Young prince.

~추가적 내용 정리~
1. scanf() 사용 시 버퍼 유의.
변환문자 d 사용 시에는 개행문자를 제거해 주기 때문에 그냥 사용하면 됨.
변환문자 c 사용 시 개행문자를 제거해 주지 않기 때문에 유의해야 함.

2. 경우 빠뜨리지 않도록.
모든 경우를 포함할 수 있도록 하자.

3. 너무 하찮아서 자괴감에 빠질 만한 실수.
실수는 언제나 발생할 수 있다. 다만 빠르게 알아차리고 고쳐버리는 것이 핵심.
*/

#include <stdio.h>

#define D_NUM   50
#define M_NUM   3       //x, y, r

#define pow_2(x)    ((x) * (x))

int d[D_NUM][M_NUM] = { 0 };
int data_num = 0;

void arr_reset(void)
{
    for(int i = 0; i < data_num; i++)
    {
        for(int j = 0; j < M_NUM; j++)
        {
            d[i][j] = 0;
        }
    }

    return;
}

void arr_input(void)
{
    scanf("%d", &data_num);

    for(int i = 0; i < data_num; i++)
    {
        scanf("%d%d%d", &(d[i][0]), &(d[i][1]), &(d[i][2]));
    }

    return;
}

int prince_cal(int x1, int y1, int x2, int y2)
{
    int pass = 0;
    int r1, r2;

    for(int i = 0; i < data_num; i++)
    {
        r1 = (int)(pow_2(d[i][2]) > (pow_2(d[i][0] - x1) + pow_2(d[i][1] - y1))); //1->in, 0->out
        r2 = (int)(pow_2(d[i][2]) > (pow_2(d[i][0] - x2) + pow_2(d[i][1] - y2))); //1->in, 0->out

        if((r1 == 1) && (r2 == 1))
        {
            continue;
        }
        else if((r1 == 1) || (r2 == 1))
        {
            pass++;
        }
    }

    return pass;        
}

int main(void)
{
    int t, x1, x2, y1, y2;
    scanf("%d", &t);

    for(int i = 0; i < t; i++)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        arr_reset();
        arr_input();
        printf("%d\n", prince_cal(x1, y1, x2, y2));
    }

    return 0;
}