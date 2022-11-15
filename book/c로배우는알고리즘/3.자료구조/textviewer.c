/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 11. 12.
Textviewer using doubly linked list by chapter 3 of c로배우는알고리즘.

~conception~
./a.out file.txt와 같이 입력한 경우 해당 텍스트파일을 확인할 수 있음.
디스크의 텍스트파일은 문장 단위로 node에 저장함. 이때 .을 기준으로 구분.
화면에 10줄씩 문장을 출력한 후, 위아래로 움직여 이전/이후 문장을 확인할 수 있음.
특정 키를 누르면 프로그램 종료.

~limit~
문장을 .으로 구분하기 때문에 마침표로서 쓰이지 않은 .에 대해서는 처리되지 않음.(추후에 기능 추가하기.)
. 뒤의 공백문자 처리.
한글 입출력. -> 현재는 한글 1글자당 3바이트를 사용하는 것으로 보이고(UTF-8), 영어와 혼용 가능함.
문장을 배열에 저장했다가 list에 올리기 때문에 배열 크기에 따른 제한 존재.

~data structure~
doubly linked list 사용.
head pointer, tail pointer 사용.
처음과 끝 노드의 빈 주소 저장공간에는 NULL 저장.
저장 시에는 head pointer쪽에, 사용 시에는 tail pointer쪽에서.

~Work Step~
전체 과정
1. 파일 읽어서 list 생성하기.
2. list 출력하기.

~추가적 내용 정리~
1. 문자 처리 방식 한 번 읽어보자.
    https://m.blog.naver.com/ruvendix/220904631516
    https://programmerpsy.tistory.com/110
2. getch() 함수 제작법 알아보자.
    https://anythink.tistory.com/entry/Linux-%EB%A6%AC%EB%88%85%EC%8A%A4%EC%97%90%EC%84%9C-getch-%EC%82%AC%EC%9A%A9
3. 비디오 메모리 등 더 low한 부분을 다룰 수 있는지?

컨디션/집중도 관리?
*/

#include <stdio.h>
#include <stdlib.h>
#include <termio.h>
#include <string.h>

//This #define preprocessor sector can be revised
#define STR_LENGTH  500
#define PRINT_QUAN  5

typedef struct node
{
    struct node *prev_ptr;
    struct node *next_ptr;
    char *str;
}NODE;

NODE *head_ptr = NULL;
NODE *tail_ptr = NULL;

void cre_node(char buffer[STR_LENGTH])
{
    NODE *new;

    if(buffer[0] == 0)
    {
        return;
    }

    if(head_ptr == NULL)
    {
        head_ptr = (NODE *)malloc(sizeof(NODE));
        head_ptr->prev_ptr = NULL;
        head_ptr->next_ptr = NULL;
        head_ptr->str = (char *)malloc(sizeof(char) * strlen(buffer));
        strcpy(head_ptr->str, buffer);

        tail_ptr = head_ptr;
    }
    else
    {
        new = (NODE *)malloc(sizeof(NODE));
        new->prev_ptr = NULL;
        new->next_ptr = head_ptr;
        new->str = (char *)malloc(sizeof(char) * strlen(buffer));
        strcpy(new->str, buffer);

        head_ptr->prev_ptr = new;
        head_ptr = new;
    }

    return;
}

void cre_list(char *filename)
{
    //opening file
    FILE *datafile = fopen(filename, "r");
    if(datafile == NULL)
    {
        printf("cre_list(): Failed to open file.\n");
        return;
    }

    char buffer[STR_LENGTH] = {0};
    int i = 0;

    while(1)
    {
        //puting data into buffer
        i = 0;
        while(1)
        {
            buffer[i] = getc(datafile);

            if(buffer[i] == '.')
            {
                buffer[i + 1] = 0;
                break;
            }
            else if(buffer[i] == EOF)
            {
                buffer[i] = 0;
                cre_node(buffer);
                fclose(datafile);
                return;
            }
            else
            {
                i++;
            }
        }

        //creating node
        cre_node(buffer);
    }
}

int getch(void)
{
    int ch;

    struct termios old;
    struct termios new;

    tcgetattr(0, &old);

    new = old;
    new.c_lflag &= ~(ICANON|ECHO);
    new.c_cc[VMIN] = 1;
    new.c_cc[VTIME] = 0;

    tcsetattr(0, TCSAFLUSH, &new);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &old);

    return ch;
}

void text_print(void)
{
    char tmp = 0;
    NODE *test_ptr;

    do
    {
        system("clear");
        printf("<textviewer>\n");
        printf("--------------------------------------------------\n");
        printf("Press 'j' or 'k' or 'q'. (j: up, k: down, q: quit)\n");
        printf("--------------------------------------------------\n");

        if((tmp == 'j') && (tail_ptr->next_ptr != NULL))
        {
            tail_ptr = tail_ptr->next_ptr;
        }
        else if((tmp == 'k') && (tail_ptr->prev_ptr != NULL))
        {
            tail_ptr = tail_ptr->prev_ptr;
        }

        test_ptr = tail_ptr;
        for(int i = 0; (i < PRINT_QUAN) && (test_ptr != NULL); i++)
        {
            printf("%s\n\n", test_ptr->str);

            test_ptr = test_ptr->prev_ptr;
        }
    }while((tmp = getch()) != 'q');

    return;
}

int main() //int argc, char *argv[]
{   
    //test
    char test[] = "textfile.txt";
    //testend

    //read file, create list
    cre_list(test); //test
    if(head_ptr == NULL)
    {
        printf("main(): Error occured\n");
        return 0;
    }

    //print textfile
    text_print();

    return 0;
}