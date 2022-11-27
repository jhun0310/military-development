/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 11. 26.~ 22. 11. 27.
CALC(calculation) utility. 계산기!

~conception~
중위표기법 수학 수식을 후위표기법으로 변환하여, 스택에 저장한 후 연산하는 프로그램.
데이터 입력 -> 후위로 전환 -> 최종 연산

~limit~
1. 사칙연산만을 사용할 수 있음. (+, -, *, /, 괄호)
2. 각 연산자의 수식을 전부 괄호 처리해야 함. (연산자들 간의 우선순위를 판별하지 못함.)
3. 소수의 연산을 지원하지 않음.
4. 0을 나누는 등의 경우에 대해 정확한 예외처리는 되어있지 않음.
5. 입력 시에는 9이하 정수만 호환이 됨.

~data structure~
1개의 전역 스택.
head pointer 사용.
마지막 노드의 주소 멤버에는 NULL 저장.
멤버로는 문자 저장 변수 하나와 포인터 하나.

~Work Step~

~추가적 내용 정리~
1. stack의 활용도
stack은 단순히 중요 데이터들을 저장하는 것 이상의 쓰임새를 가지고 있는 것 같다.
임시로 데이터를 저장하는 기능으로서 유용하다.
데이터의 처리 순서를 내가 원하는 시점으로 바꿀 수 있다.
데이터를 분리할 때도 유용하다.

2. 예외 처리
모든 경우를 시도해보는 것 보다는, 설계 시에 논리적으로 완벽해야 한다.

3. 해답
문제에 대해 고민하다가 그 해답을 봐 버리면 흥미가 급격히 떨어진다.
최대한 혼자 답을 내 보자.

4. 아이디어
어떻게 복잡한 문제에 대한 최선의 아이디어를 낼 수 있을까?
일단 만들고 개선하기?
여러 문제 접해보기?
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next_ptr;
}NODE;

typedef struct node_i
{
    int data_i;
    struct node_i *next_ptr;
}NODE_I;

NODE *head_ptr = NULL;

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

void push_i(NODE_I **ptr, int data) //ptr(head)의 stack에 data를 push함
{
    NODE_I *tmp;

    if((*ptr) == NULL)
    {
        (*ptr) = (NODE_I *)malloc(sizeof(NODE_I));
        (*ptr)->data_i = data;
        (*ptr)->next_ptr = NULL;
    }
    else
    {
        tmp = (NODE_I *)malloc(sizeof(NODE_I));
        tmp->data_i = data;
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

int pop_i(NODE_I **ptr) //ptr(head)의 stack에서 데이터 하나를 pop하여 리턴
{
    int data;
    NODE_I *tmp;

    if((*ptr) == NULL)
    {
        return 0;
    }
    else
    {
        data = (*ptr)->data_i;
        tmp = (*ptr);
        (*ptr) = (*ptr)->next_ptr;
        free(tmp);
        return data;
    }
}

void backward_arr(char d) //전역 head_ptr 필요
{
    static NODE *side_stack = NULL;

    if((d == '(') || (d == ' '))
    {
        return;
    }
    else if((d == '+') || (d == '-') || (d == '*') || (d == '/'))
    {
        push(&side_stack, d);
    }
    else if(d == ')')
    {
        push(&head_ptr, pop(&side_stack));
    }
    else //나머지는 숫자 문자
    {
        push(&head_ptr, d);
    }

    return;
}

void rearr(void)
{
    NODE *tmp = head_ptr;
    head_ptr = NULL;

    while(tmp != NULL)
    {
        push(&head_ptr, pop(&tmp));
    }

    return;
}

int backward_cal(NODE *ptr) //후위표기법 수식의 연산, 전역 head ptr 필요
{
    char n1 = 0, n2 = 0; //n1이 앞, n2가 뒤
    char d;
    NODE_I *side_stack = NULL;

    while((d = pop(&head_ptr)) != 0)
    {
        if((d == '+') || (d == '-') || (d == '*') || (d == '/'))
        {
            n1 = pop_i(&side_stack);
            n2 = pop_i(&side_stack);
            switch(d)
            {
                case '+':
                    push_i(&side_stack, n2 + n1);
                    break;
                case '-':
                    push_i(&side_stack, n2 - n1);
                    break;
                case '*':
                    push_i(&side_stack, n2 * n1);
                    break;
                case '/':
                    push_i(&side_stack, n2 / n1);
                    break;    
            }
        }
        else //숫자인 경우
        {
            push_i(&side_stack, (d - 48));
        }
    }

    return pop_i(&side_stack);
}

void calc(void)
{
    //input
    char d;
    printf("수식을 입력하세요. : ");
    while((d = getchar()) != '\n')
    {
        backward_arr(d); //중위표기법 수식을 후위표기법으로 저장
    }

    //rearray, stack 데이터 뒤집기
    rearr();

    //cal
    printf("answer : %d\n", backward_cal(head_ptr));

    return;
}

int main(void)
{
    system("clear");
    while(1)
    {
        calc();
    }

    return 0;
}