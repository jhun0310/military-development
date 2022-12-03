/*
Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
Date: 22. 12. 2.
Baekjoon 3053th quiz.
Taxi geometry.

~추가적 내용 정리~
1. 수학적 문제해결능력
문제로의 수학적 접근은 코드/알고리즘을 비약적으로 단순화하도록 도와준다.

2.
데이터를 다룰 때는 자료형이 그 데이터에 적절한지를 따지자.
*/

#include <stdio.h>
#define M_PI 3.1415926535897932384626

int main(void)
{
    double n;
    scanf("%lf", &n);

    printf("%f\n%f", (M_PI * n * n), (2 * n * n));

    return 0;
}