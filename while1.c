#include <stdio.h>
 
int main()
{
    char c;     // 입력받을 값
    while(1)    // 무한루프
    {
        scanf("%c", &c);    // 값 입력
        printf("%c", c);    // 출력
        if(c == 'q')        // 입력받은 문자가 q라면
            break;          // 반복문 종료 
    }
    return 0;
}

