/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 11. 27.
Parse tree & traverse.

~conception~
제공된 후위표기법을 이진 수식 트리로 만든다.
만들어진 트리를 전위/중위/후위/층별 순회로 확인한다.

~limit~

~data structure~
이진 트리.
head pointer 사용.
멤버는 char형 변수 하나, 주소 2개.
외부 노드에는 피연산자가, 내부 노드에는 연산자가 저장됨.
외부 노드의 주소에는 NULL.

~Work Step~

~추가적 내용 정리~
1. 프로그램의 설계와 코드는 단순해야 한다.
단순함을 정의로.
일단 만들고 단순화하자.

2. 트리 자체를 스택에 넣어 버리는 기법.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tree //node for tree
{
    char data;
    struct tree *left_ptr;
    struct tree *right_ptr;
}TREE_NODE;

typedef struct node //node for stack
{
    TREE_NODE *data;
    struct node *next_ptr;
}NODE;

void push_t(NODE **ptr, TREE_NODE *data) //ptr(head)의 stack에 data를 push함
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

TREE_NODE *pop_t(NODE **ptr) //ptr(head)의 stack에서 데이터 하나를 pop하여 리턴
{
    TREE_NODE *data;
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

TREE_NODE *cre_tree(void)
{
    char d;
    TREE_NODE *tmp;
    NODE *head_stack_ptr;

    printf("후위표기법 수식을 입력하세요. : ");
    while((d = getchar()) != '\n')
    {
        tmp = (TREE_NODE *)malloc(sizeof(TREE_NODE));
        tmp->data = d;

        if((d == '+') || (d == '-') || (d == '*') || (d == '/'))
        {
            tmp->right_ptr = pop_t(&head_stack_ptr);
            tmp->left_ptr = pop_t(&head_stack_ptr);
        }
        else //숫자인 경우
        {
            tmp->left_ptr = NULL;
            tmp->right_ptr = NULL;
        }

        push_t(&head_stack_ptr, tmp);
    }

    return pop_t(&head_stack_ptr);
}

void preorder_traverse(TREE_NODE *ptr)
{
    if(ptr != NULL)
    {
        printf("%c ", ptr->data);
        preorder_traverse(ptr->left_ptr);
        preorder_traverse(ptr->right_ptr);
    }

    return;
}

void inorder_traverse(TREE_NODE *ptr)
{
    if(ptr != NULL)
    {
        inorder_traverse(ptr->left_ptr);
        printf("%c ", ptr->data);
        inorder_traverse(ptr->right_ptr);
    }

    return;
}

void postorder_traverse(TREE_NODE *ptr)
{
    if(ptr != NULL)
    {
        postorder_traverse(ptr->left_ptr);
        postorder_traverse(ptr->right_ptr);
        printf("%c ", ptr->data);
    }

    return;
}

int main(void)
{
    //create tree
    TREE_NODE *head_tree_ptr = cre_tree();

    //traverse tree
    preorder_traverse(head_tree_ptr);
    printf("\n");
    inorder_traverse(head_tree_ptr);
    printf("\n");
    postorder_traverse(head_tree_ptr);
    printf("\n");

    return 0;
}