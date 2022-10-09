/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 03.
* Baekjoon 10250th question.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next_node_ptr;
    int data;
}NODE;

int main(void)
{
    int loop, h, w, n;
    NODE *head_ptr = NULL;
    NODE *tail_ptr = NULL;

    //input
    scanf("%d", &loop);

    //calculate
    for(int i = 0; i < loop; i++)
    {
        scanf("%d%d%d", &h, &w, &n);

        if(head_ptr == NULL) //creating first node
        {
            head_ptr = (NODE *)malloc(sizeof(NODE));
            tail_ptr = head_ptr;
            head_ptr->next_node_ptr = NULL;

            if((n % h) == 0)
            {
                head_ptr->data = ((h * 100) + (n / h));
            }
            else
            {
                head_ptr->data = (((n % h) * 100) + ((n / h) + 1));
            }
        }
        else //first node existing
        {
            tail_ptr->next_node_ptr = (NODE *)malloc(sizeof(NODE));
            tail_ptr = tail_ptr->next_node_ptr;
            tail_ptr->next_node_ptr = NULL;
            
            if((n % h) == 0)
            {
                tail_ptr->data = ((h * 100) + (n / h));
            }
            else
            {
                tail_ptr->data = (((n % h) * 100) + ((n / h) + 1));
            }
        }
    }

    //output
    NODE *tmp_ptr = NULL;

    while(1)
    {
        printf("%d\n", head_ptr->data);

        if(head_ptr->next_node_ptr == NULL)
        {
            free(head_ptr);
            break;
        }
        else
        {
            tmp_ptr = head_ptr;
            head_ptr = head_ptr->next_node_ptr;
            free(tmp_ptr);
        }
    }

    return 0;
}