#include <stdio.h>
 
int main()
{
    int i, num, odd=0, even=0;
    int t;
 
    for (i=0; i<10; i++) {
 
        printf ("입력받으세요 : ");
        scanf ("%d", &num);
 
        if (num % 2 == 0)
            even++;
 
        if (num % 2 == 1)
            odd++;
 
    }
 
    printf ("짝수 개수 : %d\t 홀수 개수 : %d",even, odd);
 
    return 0;
 }



