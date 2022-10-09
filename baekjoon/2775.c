/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 03.
* Baekjoon 2775th question.
*/

#include <stdio.h>
#include <stdlib.h>

int prog_cre(void)
{
    //settings
    int  k, n; //k floor room n.
    int **data = NULL; //upper level(k, floor) goes at it is. lower level(n, room) goes -1.

    scanf("%d%d", &k, &n);
    data = (int **)malloc(sizeof(int *) * (k + 1));

    for(int i = 0; i < (k + 1); i++)
    {
        data[i] = (int *)malloc(sizeof(int) * n); //*(data + i)
    }

    for(int i = 0; i < (k + 1); i++) //each floor room 1.
    {
        data[i][0] = 1;
    }

    for(int i = 0; i < n; i++) //floor 1 each room.
    {
        data[0][i] = (i + 1);
    }

    //building progression
    for(int i = 1; i < (k + 1); i++)
    {
        for(int j = 1; j < n; j++)
        {
            data[i][j] = (data[i - 1][j] + data[i][j - 1]);
        }
    }

    return data[k][n - 1];
}

int main(void)
{
    int loop;
    int *answer_ptr = NULL;
    
    scanf("%d", &loop);
    answer_ptr = (int *)malloc(sizeof(int) * loop);

    for(int i = 0; i < loop; i++)
    {    
        answer_ptr[i] = prog_cre();
    }

    for(int i = 0; i < loop; i++)
    {
        printf("%d\n", answer_ptr[i]);
    }

    return 0;
}


/*
0 : 1   2   3   4   5   6
1 : 1   3   6   10  15  21
2 : 1   4   10  20  35  56
3 : 1   5   15  35
4 : 1   6   21  56
5 : 1   7   28  84
6 : 1   8   36  120
7 : 1   9   45  165

1. 0층부터 전부 계산한다. -> go.
2. 특정 규칙을 찾아 필요한 위치의 값만 알아낸다.
*/






