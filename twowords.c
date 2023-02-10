#include <stdio.h>
 
int main()
{
    int i, num1, num2, t;
 
    printf ("두 수를 입력하세요 : ");
    scanf ("%d %d",&num1, &num2);
 
    for (i=num1; i<=num2; i++)
 
        printf ("%d ",i);
 
    return 0;
 
}

