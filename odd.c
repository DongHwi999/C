#include <stdio.h>
 
int main()
{
    int i, num, odd=0, even=0;
    int t;
 
    for (i=0; i<10; i++) {
 
        printf ("�Է¹������� : ");
        scanf ("%d", &num);
 
        if (num % 2 == 0)
            even++;
 
        if (num % 2 == 1)
            odd++;
 
    }
 
    printf ("¦�� ���� : %d\t Ȧ�� ���� : %d",even, odd);
 
    return 0;
 }



