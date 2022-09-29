#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b, c, e = 1, f = 1;
    char d;

    c = 1;

    while(c == 1)
    {
        printf("두 정수를 비교합니다. 두 정수를 각각 입력하세요.\n");

        printf("첫 번째 정수 : ");
        scanf("%d", &a);
        printf("두 번째 정수 : ");
        scanf("%d", &b);

        if(a > b)
        {
            printf("첫 번째가 더 큽니다!\n");
        }
        else if(a < b)
        {
            printf("두 번째가 더 큽니다!\n");
        }
        else
        {
            printf("두 수가 같습니다!\n");
        }

        while(1)
        {
            getchar();

            printf("다시 하시겠습니까?(y/n) : ");
            d = getchar();

            switch(d)
            {
                /*
                case (int)((d == 'Y') || (d == 'y')) :
                    break;
                case (int)((d == 'N') || (d == 'n')) :
                    e = 0;
                    break;
                */
                case 'Y' :
                    f = 2;
                    break;
                case 'y' :
                    f = 2;
                    break; 
                case 'N' :
                    f = 2;
                    e = 0;
                    break;
                case 'n' :
                    f = 2;
                    e = 0;
                    break;
                default :
                    printf("잘못된 입력입니다. 다시 입력하세요.\n");
                    break;
            }

            if(f == 2)
            {
                break;
            }
        }

        if(e == 0)
        {
            break;
        }

        printf("\n");
    }

    return 0;
}