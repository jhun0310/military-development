//포인터 연습

#include <stdio.h>

#define TEST_NUM 10

int main(void)
{
    char *test_ptr[TEST_NUM] = {"for", "test"};

    printf("%s %s\n", test_ptr[0], test_ptr[1]);

    return 0;
}