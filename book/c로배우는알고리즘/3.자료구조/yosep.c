/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 11. 07.
* Yosep's Problem by chapter 3 of c로배우는알고리즘.

~Work Step~
1. 사람의 수 n, 간격 step을 입력받는다.
2. n만큼의 노드를 가진 circular linked list를 만든다.
(head pointer 형식으로. node가 1개이면 next_ptr에는 NULL이 들어감.)
3. step씩 넘어가며 사람을 출력하고, node를 삭제한다.
    1. head_ptr과 prev_h_ptr이 같은지 확인.
        1. 같다면 braek.
        2. 다르다면 go.
    2. head_ptr이 가리키고 있는 노드 출럭/제거. head_ptr은 다음 노드를 가리키게 함.
    3. head_ptr을 (n-1)번 다음 노드로 이동.
    4. head_ptr 이동 시에는 prev_h_ptr도 이동.
    5. 1로 이동
4. head_ptr->name 출력.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char name;
    struct node *next_ptr;
}CIR_NODE;

void user_data_input(int *n, int *step)
{
    printf("<Yosep's Problem>\nEnter the number of people : ");
    scanf("%d", n);
    printf("Enter the interval : ");
    scanf("%d", step);

    return;
}

CIR_NODE *cir_list_gen(int node_num) //node_num should be a positive integer.
{
    CIR_NODE *head_ptr = malloc(sizeof(CIR_NODE));
    head_ptr->name = 'A';
    head_ptr->next_ptr = NULL;
    
    for(int i = 1; i < node_num; i++)
    {
        
    }
    
    return head_ptr;
}

void main(void)
{
    int n, step;
    CIR_NODE *head_ptr = NULL;

    user_data_input(&n, &step);
    head_ptr = cir_list_gen(n);



    return 0;
}
