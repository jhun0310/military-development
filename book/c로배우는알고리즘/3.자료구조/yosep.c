/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 11. 07. ~ 22. 11. 08.
Yosep's Problem by chapter 3 of c로배우는알고리즘.

~Work Step~
1. 사람의 수 n, 간격 step을 입력받는다.
2. n만큼의 노드를 가진 circular linked list를 만든다.
(head pointer 형식으로. node가 1개이면 next_ptr에는 자신의 주소가 들어감.)
3. step씩 넘어가며 사람을 출력하고, node를 삭제한다.
    1. head_ptr과 head_ptr->next_ptr이 같은지 확인.
        1. 같다면 break.
        2. 다르다면 go.
    2. head_ptr이 가리키고 있는 노드 다음 노드 출럭/제거.
    3. head_ptr을 (n-1)번 다음 노드로 이동.
    4. 1로 이동
4. head_ptr->name 출력.
(마지막 data.)

~추가적 내용 정리~
1. head pointer 형식의 circular linked list의 유의점.
삽입 시에는 head pointer가 가리키는 노드 뒤에 삽입하는 것이 간단함.
삭제 시에는 head_pointer가 가리키는 노드 다음 노드를 삭제하는 것이 간단함.(double linked list가 아니므로.)
circular linked list는 단순하게 singly linked list를 만든 후 마지막 노드와 첫 노드를 이어줌으로서 쉽게 구현할 수 있음.

2. 본 프로그램을 만들고 검토하며 느낀점.
    1. 포인터 연산이 많이 들어가는 등, 한 번에 알아보기 어려운 코드는 함수로 만들어 가독성을 높이는 것이 좋을 듯.
    2. 길이가 짧고 많은 변수가 쓰이지 않는 함수에서는 변수명을 최대한 간단히 하는 것(d, t 등으로..?)이 가독성을 높이는 데에 도음이 된다.
    3. main()의 코드는 최대한 간단하게 하는 것이 깔끔해 보인다.
    4. 함수를 적극적으로 사용하자. 일단 깔끔하고 쉽게 만들고, 개선하는 것이다. 속도 결벽증에 빠지지 말자.
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
    if(!(node_num > 0))
    {
        printf("cir_list_gen(): wrong input detected.\n");
        return NULL;
    }

    CIR_NODE *head_ptr = (CIR_NODE *)malloc(sizeof(CIR_NODE));
    CIR_NODE *tmp_ptr = NULL;
    head_ptr->name = 'A';
    head_ptr->next_ptr = head_ptr;
    
    for(int i = 1; i < node_num; i++)
    {
        if(i == 1)
        {
            head_ptr->next_ptr = (CIR_NODE *)malloc(sizeof(CIR_NODE));
            head_ptr->next_ptr->name = 'B';
            head_ptr->next_ptr->next_ptr = head_ptr;
            head_ptr = head_ptr->next_ptr;
        }
        else
        {
            tmp_ptr = (CIR_NODE *)malloc(sizeof(CIR_NODE));
            tmp_ptr->name = 'A' + i;
            tmp_ptr->next_ptr = head_ptr->next_ptr;

            head_ptr->next_ptr = tmp_ptr;
            head_ptr = head_ptr->next_ptr;
        }
    }
    
    return head_ptr;
}

void yosep_sort(CIR_NODE *head_ptr, int step)
{
    CIR_NODE *tmp_ptr = NULL;
    step--;

    while(head_ptr != (head_ptr->next_ptr))
    {
        printf("%c ", head_ptr->next_ptr->name);

        tmp_ptr = head_ptr->next_ptr;
        head_ptr->next_ptr = head_ptr->next_ptr->next_ptr;
        free(tmp_ptr);

        for(int i = 0; i < step; i++)
        {
            head_ptr = head_ptr->next_ptr;
        }
    }

    printf("%c\n", head_ptr->name);
    free(head_ptr);

    return;
}

int main(void)
{
    int n, step;
    CIR_NODE *head_ptr = NULL;

    //input
    user_data_input(&n, &step);
    
    //generating circular linked list
    head_ptr = cir_list_gen(n);
    if(head_ptr == NULL)
    {
        return 0;
    }

    //solving Yosep's problem
    yosep_sort(head_ptr, step);

    return 0;
}
