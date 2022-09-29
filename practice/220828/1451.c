//여러 개의 문자열을 입력받은 후, 버블 정렬로 사전순으로 정렬하는 프로그램. (버블 정렬, 동적 메모리 할당, 함수 등 연습.)
//제작 후, linked list 형식으로 수정해보기.

//전처리기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TMP_ARRAY_SIZE 50

//함수 원형 선언


//함수
int main(void)
{
    //문자열 입력, 저장
    char tmp_array[TMP_ARRAY_SIZE]; //영단어 임시 저장 배열
    int word_num;

    printf("<영단어 정렬 프로그램>\n몇 개의 영단어를 입력하시겠습니까? : ");
    scanf("%d", &word_num);

    char **word_sto = (char **)malloc(sizeof(char *) * word_num);

    for(int i = 0; i < word_num; i++)
    {
        printf("영단어를 입력하세요. : ");
        scanf("%s", tmp_array);

        *(word_sto + i) = (char *)malloc(sizeof(char) * strlen(tmp_array) + 1); //NULL 문자를 저장하기 위한 공간으로 +1

        strcpy(*(word_sto + i), tmp_array);
    }


    //정렬
    for(int i = (word_num - 2); i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(strcmp(word_sto[j], word_sto[j + 1]) > 0) //바꾸는 경우
            {
                strcpy(tmp_array, word_sto[j]);
                strcpy(word_sto[j], word_sto[j + 1]);
                strcpy(word_sto[j + 1], tmp_array);
            }
        }
    }


    //출력
    printf("정렬한 결과 :\n");
    for(int i = 0; i < word_num; i++)
    {
        printf("%s\n", *(word_sto + i));
    }

    return 0;
}