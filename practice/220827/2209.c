//문자열을 입력받아 배열에 저장하는 함수

//전처리기
#include <stdio.h>

#define FOR_TEST 30


//함수 원형 선언
void arr_input(char sto_arr[], int arr_size);


//함수
int main(void)
{
    //배열 선언
    char test_arr[FOR_TEST] = {0};

    //문자열 입력
    arr_input(test_arr, FOR_TEST);

    //배열에 저장된 문자열 출력
    printf("입력한 문자열은 \"%s\"입니다.\n", test_arr);

    return 0;
}

//문자열을 입력받아 매개변수로 전달받은 배열에 저장하는 함수. (getchar() 써보기.)
void arr_input(char sto_arr[], int arr_size)
{
    printf("%d자 이하의 영단어를 작성하세요. : ", arr_size);

    char sto;

    for(int i = 0; i < (arr_size + 1); i++)
    {
        //문자 입력받기
        sto = getchar();

        //문자열 입력이 끝났는지 검사
        if((sto == '\n') || (sto == '\r') || (sto == ' '))
        {
            break;
        }

        //문자열이 너무 길어지는 경우
        if(i == arr_size)
        {
            printf("문자열이 너무 깁니다! %d자까지만 저장합니다.\n", arr_size);

            return;
        }

        //문자를 배열에 저장
        sto_arr[i] = sto;
    }

    return;
}