/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* Date: 22. 10. 03.
* Baekjoon 10757th question.
* Although this code seemed perfect, it had a serious bug. OutOfBound message was returned when I permitted the code.
* While debugging code, I guess this problem is bacause of the strlen and NULL pointer.
* Since I set SIZE preprocessor 10000, the maximum number cannot has NULL pointer. And maybe this is why strlen returned wrong number.
*/

#include <stdio.h>
#include <string.h>

#define SIZE 10001

int main(void)
{
    char a[SIZE] = { 0 };
    char b[SIZE] = { 0 };
    char result[SIZE] = { 0 };

    scanf("%s%s", a, b);

    int left_num = 0; //a digit that will be added to the upper digit.
    int a_size = strlen(a);
    int b_size = strlen(b);
    int ab_diff = ((a_size - b_size) >= 0) ? (a_size - b_size) : (b_size - a_size); //absolute value.
    int total_len = ((a_size - b_size) >= 0) ? a_size : b_size; //longer one.

    //adjustment of a&b.
    if(a_size > b_size)
    {
        for(int i = (b_size - 1); i >= 0; i--)
        {
            b[i + ab_diff] = b[i];
            b[i] = 0;
        }
    }
    else if(a_size < b_size)
    {
        for(int i = (a_size - 1); i >= 0; i--)
        {
            a[i + ab_diff] = a[i];
            a[i] = 0;
        }
    }
    else //if(a_size == b_size)
    {
        ;
    }

    //output(reusing a array.)
    for(int i = (total_len - 1); i >= 0; i--)
    {
        if(a[i] == 0)
        {
            a[i] = '0';
        }
        if(b[i] == 0)
        {
            b[i] = '0';
        }

        if((a[i] - '0' + b[i] - '0' + left_num) >= 10)
        {
            result[i] = a[i] + b[i] - '0' + left_num - 10;
            left_num = 1;
        }
        else
        {
            result[i] = a[i] + b[i] - '0' + left_num;
            left_num = 0;
        }
    }

    if(left_num == 1)
    {
        printf("1");
    }

    printf("%s", result);

    return 0;
}