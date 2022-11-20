/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 11. 18.
Test for Queue.

배열로 큐 구현하기.
1. 매번 한 칸씩 밀기. (선택됨)
2. 원형 큐 사용.

~추가적 내용 정리~
1. scanf()를 사용해서 입력받을 때 enter로 입력을 끝냈다면 버퍼에는 enter가 남아있음.
*/

#include <stdio.h>
#define Q_SIZE  10 

int queue[Q_SIZE];
int k = -1; //데이터가 들어있는 최대 인덱스 값. -1이면 비어있는 것, Q_SIZE - 1이면 꽉 찬 것.

void q_put(int value)
{
    if(k == (Q_SIZE - 1))
    {
        printf("q_put(): Queue is already full.\n");
        return;
    }

    for(int i = k; i >= 0; i--)
    {
        queue[i + 1] = queue[i];
    }
    queue[0] = value;
    k++;

    return;
}

int q_get()
{
    int data = queue[k];

    if(k < 0)
    {
        printf("q_get(): Queue is empty.\n");
        return (-1);
    }
    else
    {
        k--;
        return data;
    }
}

void q_show(void)
{
    if(k == -1)
    {
        printf("empty\n");
    }
    else
    {
        for(int i = 0; i <= k; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }

    return;
}

int main(void)
{
    char d, a = 0;
    int data;
    printf("p : put\ng : get\nq : quit\ns : show\n");
    while(a != 1)
    {
        printf("명령을 입력하세요> ");
        d = getchar();
        getchar();
        switch (d)
        {
            case 'p' :
                printf("New data : ");
                scanf("%d", &data);
                getchar();
                q_put(data);
                break;
            case 'g' :
                q_get();
                break;
            case 'q' :
                a = 1;
                break;
            case 's' :
                q_show();
                break;
        }
    }

    return 0;
}