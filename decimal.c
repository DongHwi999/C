#include <stdio.h>
 
int main()
{
    int num, i, cnt=0;
 
 
    printf ("숫자를 입력하세요 : ");
    scanf ("%d", &num);
 
 
    for (i=2; i<num; i++) {
            printf ("%d %% %d = %d\n",num,i,num%i);
            if (num % i == 0)
                cnt++;
    }
 
    
    if ( cnt == 0 )
        printf ("소수 입니다");
    else 
        printf ("소수가 아닙니다");
 
 
    return 0;
 }



