/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 11. 20.
Test for Queue.

배열로 큐 구현하기.
1. 매번 한 칸씩 밀기.
2. 원형 큐 사용. (선택됨) -> % 연산자 사용.

첫 데이터를 넣을 때 rear도 수정.
front와 rear가 같을 때까지 넣을 수 있음.

front와 rear가 같을 때까지 뺄 수 있음. 이때 빼고 rear를 -1로.

~추가적 내용 정리~
1. 원형 큐를 이용할 때는 front와 rear의 표기가 필요한 듯.
2. while과 do-while의 차이는, 맨 처음 loop를 실행할 때의 조건 유무이다.
*/

#include <stdio.h>
#define SIZE    5

int q[SIZE];
int front = 0; //넣어야 되는 위치
int rear = -1; //빼내야 되는 위치, 자료가 없는 경우 -1.

void q_put(int data)
{
    if(rear == -1)
    {
        q[front] = data;
        rear = front;
        front = ((front + 1) % SIZE);

        return;
    }

    if(front == rear)
    {
        printf("q_put(): Queue is already full.\n");
        return;
    }
    else
    {
        q[front] = data;
        front = ((front + 1) % SIZE);
    }

    return;
}

int q_get()
{
    int data;

    if(rear == -1)
    {
        printf("q_get(): Queue is empty.\n");
    }
    else
    {
        data = q[rear];
        rear = ((rear + 1) % SIZE);
    }

    if(front == rear)
    {
        rear = -1;
    }

    return data;
}

void q_show(void)
{
    int tf = front;
    int tr = rear;

    if(rear == -1)
    {
        printf("empty\n");
    }
    else
    {
        do
        {
            printf("%d ", q[tr]);
            tr = ((tr + 1) % SIZE);
        }
        while(tf != tr);
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