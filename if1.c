#include <stdio.h>
 
int main()
{
    int age;
 
 
    printf ("���̸� �Է��ϼ��� : ");
    scanf ("%d", &age);
 
 
    if (age <= 6 || age >= 60)
        printf ("�����Դϴ�.");
 
    else
        printf ("1,350�� �Դϴ�.");
 
    return 0;
 }

