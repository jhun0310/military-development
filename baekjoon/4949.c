/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 12. 4.
Baekjoon 4949th quiz.

~conception~
문자열이 주어지고, 그 속의 괄호들이 균형을 이루는지 검사.
문자열은 .으로 끝남.
괄호가 없는 것도 균형잡힌 것으로 간주.
([)]와 같은 경우는 균형잡히지 않은 것으로 간주.

데이터는 문자 단위로 입력받아서 처리한다.

~data structure~
head ptr형 스택.
(), []을 char형으로 저장함.

~Work Step~
1. 데이터 가공(스택에 저장)
2. 스택의 데이터 확인 후 결과 도출

~추가적 내용 정리~
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next_ptr;
}NODE;

NODE *data_ptr;
NODE *head_ptr; //스택의 head_ptr

void push(NODE **ptr, char data) //ptr(head)의 stack에 data를 push함
{
    NODE *tmp;

    if((*ptr) == NULL)
    {
        (*ptr) = (NODE *)malloc(sizeof(NODE));
        (*ptr)->data = data;
        (*ptr)->next_ptr = NULL;
    }
    else
    {
        tmp = (NODE *)malloc(sizeof(NODE));
        tmp->data = data;
        tmp->next_ptr = (*ptr);
        (*ptr) = tmp;
    }

    return;
}

char pop(NODE **ptr) //ptr(head)의 stack에서 데이터 하나를 pop하여 리턴
{
    char data;
    NODE *tmp;

    if((*ptr) == NULL)
    {
        return 0;
    }
    else
    {
        data = (*ptr)->data;
        tmp = (*ptr);
        (*ptr) = (*ptr)->next_ptr;
        free(tmp);
        return data;
    }
}

int data_input() //0->end
{
    char d;

    if((d = getchar()) == '.') //맨 처음 입력이 .인 경우
    {
        return 0;
    }
    else
    {
        do
        {
            if((d == '(') || (d == '[') || (d == ')') || (d == ']'))
            {
                push(&data_ptr, d);
            }
        }while((d = getchar()) != '.');
    }

    return 1;
}

/*




*/

int brack_judge(void) //1->yes, 0->no
{
    char d, tmp;
    while((d = pop(&data_ptr)) != 0)
    {
        if((d == ')') || (d == ']'))
        {
            push(&head_ptr, d);
        }
        else if(d == '(')
        {
            if((tmp = pop(&head_ptr)) == 0)
            {
                return 0;
            }
            if(tmp != ')')
            {
                return 0;
            }
        }
        else if(d == '[')
        {
            if((tmp = pop(&head_ptr)) == 0)
            {
                return 0;
            }
            if(tmp != ']')
            {
                return 0;
            }
        }
    }

    int end = 0;
    while(pop(&head_ptr) != 0)
    {
        end = 1;
    }
    if(end == 1)
    {
        return 0;
    }

    return 1;
}

int main(void)
{
    int result;
    while(1)
    {
        if(data_input() == 0)
        {
            break;
        }
        else
        {
            printf("%s\n", brack_judge() ? "yes" : "no");
        }
        getchar();
    }

    return 0;
}