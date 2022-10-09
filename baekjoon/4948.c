/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 05.
* Baekjoon 4948th question.
* The code based on 1929.c.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next_ptr;
    int data;
}NODE;

int main(void)
{
    int M, N;
    int *data_ptr = NULL;
    
    NODE *head_ptr = NULL;
    NODE *tail_ptr = NULL;

    //input, calculate.
    while(1)
    {
        scanf("%d", &M);

        if(M == 0)
        {
            break;
        }
        else //creating new node.
        {
            if(head_ptr == NULL)
            {
                head_ptr = (NODE *)malloc(sizeof(NODE));
                tail_ptr = head_ptr;
                head_ptr->next_ptr = NULL;
                head_ptr->data = 0;
            }
            else
            {
                tail_ptr->next_ptr = (NODE *)malloc(sizeof(NODE));
                tail_ptr = tail_ptr->next_ptr;
                tail_ptr->next_ptr = NULL;
                tail_ptr->data = 0;
            }
        }

        N = (2 * M);
        M++;

        data_ptr = (int *)malloc(sizeof(int) * N); //1 -> non-prime, 0 -> prime. number N is in (N - 1).
        for(int i = 0; i < N; i++)
        {
            data_ptr[i] = 0;
        }

        data_ptr[0] = 1;
        for(int i = 2; i < N; i++) //sieve
        {
            if(data_ptr[i - 1] == 1)
            {
                continue;
            }
            else
            {
                for(int j = 2; (j * i) <= N; j++)
                {
                    data_ptr[(j * i) - 1] = 1;
                }
            }
        }

        for(int i = M; i <= N; i++)
        {
            if(data_ptr[i - 1] == 0)
            {
                if(head_ptr->next_ptr == NULL)
                {
                    (head_ptr->data)++;
                }
                else
                {
                    (tail_ptr->data)++;
                }
            }
        }   

        free(data_ptr);
    }
    
    NODE *tmp_ptr = NULL;

    //output
    while(head_ptr != NULL)
    {
        printf("%d\n", head_ptr->data);
        tmp_ptr = head_ptr;
        head_ptr = head_ptr->next_ptr;
        free(tmp_ptr);
    }

    return 0;
}


/*
10 20   11 13 17 19
13 26   13 17 19 23


*/