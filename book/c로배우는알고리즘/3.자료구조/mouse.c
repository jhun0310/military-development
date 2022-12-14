/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
22. 10. 23.
This program is about maze and the shortest path.

사용할 알고리즘.
1. UP, RIGHT, DOWN, LEFT 연산
2. 우선법
    오른쪽으로 돌기 -> 막혀있으면 왼쪽으로. 뚫린 곳 나올때까지 -> 앞으로.
3. 중복되는 부분 제거 -> 최단경로


임의의 맵에서도 호환되도록. 단, 맵은 출입구를 제외하고는 벽으로 둘러싸여 있어야 함.

맵, 이동한 경로는 전역변수.
좌표는 0~18로 하고, gotoxy() 인자에 사용할 때는 +1씩 하기.

- 함수
맵출력
    1. 맵 출력.

쥐 이동
    0. 쥐 좌표, 방향 변수 선언.

    1. 맵&쥐 출력.
    2. 탈출 여부 확인.
        2.1. 탈출했다면 7번으로.
        2.2. 탈출하지 못했다면 진행.
    3. 오른쪽으로 돌기.
    4. 막혀있다면
        2.1. 뚫려있을 때까지 왼쪽으로 돌기.
    5. 앞으로 가기(좌표수정).
    6. 1로 가기.
    7. 탈출했으면 record에 -1 넣고 끝.

최단경로로 되돌아가기

record
    1. 전역변수에 현재 좌표 저장.



~참고~
우선법을 이용하여 중복되는 경로를 제거하는 방식은 문제가 있다.
쥐가 지났던 적이 없는 부분에 대해서는 평가할 수가 없다.
다시 말해, 진정한 의미의 최단 경로라고는 말할 수 없다는 것.
*/

#include <stdio.h>
#include <stdlib.h>

#define UP          1
#define RIGHT       2
#define DOWN        4
#define LEFT        8

//settings depending on the map
#define MAZE_SIZE_X 19
#define MAZE_SIZE_Y 19
#define FIRST_X     (MAZE_SIZE_X - 1)
#define FIRST_Y     (MAZE_SIZE_Y - 2)
#define FIRST_DIR   LEFT

//program sleep time
#define MOUSE_SLEEP "sleep 0.1"

//1->wall, 0->space
int maze_map[MAZE_SIZE_X][MAZE_SIZE_Y] =
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int **mouse_his = NULL; //recorded history
int mouse_x = FIRST_X;
int mouse_y = FIRST_Y;
unsigned int mouse_dir = FIRST_DIR;


void maze_print(void)
{
    system("clear");

    for(int i = 0; i < MAZE_SIZE_Y; i++)
    {
        for(int j = 0; j < MAZE_SIZE_X; j++)
        {
            if((i == mouse_y) && (j == mouse_x))
            {
                printf("M"); //mouse
            }
            else
            {
                printf("%c", (maze_map[i][j] ? 'O' : ' '));
            }
        }
        printf("\n");
    }

    return;
}

void his_record(int x, int y)
{
    static int index = 0;

    if(mouse_his == NULL) //first call
    {
        mouse_his = (int **)malloc(sizeof(int *) * MAZE_SIZE_X * MAZE_SIZE_Y);
        for(int i = 0; i < (MAZE_SIZE_X * MAZE_SIZE_Y); i++)
        {
            mouse_his[i] = (int *)malloc(sizeof(int) * 2);
        }
    }
    
    mouse_his[index][0] = x;
    mouse_his[index++][1] = y;

    return;
}

void end_record(void)
{
    for(int i = 0; i < MAZE_SIZE_X; i++)
    {
        free(mouse_his[i]);
    }
    free(mouse_his);

    return;
}

//1->escaped, 0->in the maze
int escape_or_not(int x, int y)
{
    if((x != FIRST_X) || (y != FIRST_Y))
    {
        if((x == 0) || (x == (MAZE_SIZE_X - 1)) || (y == 0) || (y == (MAZE_SIZE_Y - 1)))
        {
            return 1;
        }
    }

    return 0;
}

//1-> wall, 0->space
int wall_scan(int x, int y, unsigned int dir)
{
    if(dir == UP) (y--);
    if(dir == RIGHT) (x++);
    if(dir == DOWN) (y++);
    if(dir == LEFT) (x--);

    if((x < 0) || (x >= MAZE_SIZE_X) || (y < 0) || (y >= MAZE_SIZE_Y))
    {
        printf("\n***Stack Overflow : wall_scan()***\n");
        exit(0);
    }

    return maze_map[y][x];
}

void right_hand()
{
    while(1)
    {
        maze_print(); //print map & mouse
        his_record(mouse_x, mouse_y);

        if(escape_or_not(mouse_x, mouse_y)) //escaped->1, none-escaped->0
        {
            printf("Mouse escaped maze!\n");
            break;
        }

        //setting direction
        //to the right side
        if(mouse_dir == LEFT)
        {
            mouse_dir = UP;
        }
        else
        {
            mouse_dir = mouse_dir << 1;
        }

        //to the left side
        while(wall_scan(mouse_x, mouse_y, mouse_dir))
        {
            if(mouse_dir == UP)
            {
                mouse_dir = LEFT;
            }
            else
            {
                mouse_dir = mouse_dir >> 1;
            }   
        }
        
        //move forward
        if(mouse_dir == UP) (mouse_y--);
        if(mouse_dir == RIGHT) (mouse_x++);
        if(mouse_dir == DOWN) (mouse_y++);
        if(mouse_dir == LEFT) (mouse_x--);

        //sleep for visual check
        system(MOUSE_SLEEP);   
    }

    his_record(-1, -1);

    return;
}

/*
shortest_path() -> 최단 경로로 되돌아가기.
    1. 이동한 경로 검사해서 겹치는 것 제거.
    2. 남은 좌표대로 이동.
*/
void shortest_path(void)
{
    printf("Press any key to watch shortest path.");
    getchar();

    //겹치는 경로 제거
    int loop = 0;
    int inner_loop, inner_loop_2;
    int gap;

    while(mouse_his[loop][0] > 0)
    {
        inner_loop = (loop + 1);
        
        while(mouse_his[inner_loop][0] > 0)
        {
            if((mouse_his[loop][0] == mouse_his[inner_loop][0]) && (mouse_his[loop][1] == mouse_his[inner_loop][1]))
            {
                inner_loop_2 = 1;

                do
                {
                    mouse_his[loop + inner_loop_2][0] = mouse_his[inner_loop + inner_loop_2][0];
                    mouse_his[loop + inner_loop_2][1] = mouse_his[inner_loop + inner_loop_2][1];

                    inner_loop_2++;
                }while(mouse_his[inner_loop + inner_loop_2][0] > 0);

                break;
            }

            inner_loop++;
        }

        loop++;
    }

    //최단 경로 출력
    int last = 0;

    while(mouse_his[last][0] > 0)
    {
        last++;
    }
    
    for(int i = last; i >= 0; i--)
    {
        mouse_x = mouse_his[i][0];
        mouse_y = mouse_his[i][1];
        maze_print(); //print map & mouse

        //sleep for visual check
        system(MOUSE_SLEEP);
    }

    return;
}

int main(void)
{
    right_hand();

    shortest_path();

    end_record();

    return 0;
}