//drawing module

/*
1. ANSI escape sequence
printf("\033[%dd\033[%dG", y, x); 이건 ANSI 이스케이프 시퀀스로서, 텍스트 출력이 아닌 명령 수행을 위한 것임.
ASI임.
\033은 ESC를 의미함.

void movexy(int x, int y)
{
    printf("\033[%dd\033[%dG", y, x);
}
*/