#include <stdio.h>
 
int main()
{
    int age;
 
 
    printf ("나이를 입력하세요 : ");
    scanf ("%d", &age);
 
 
    if (age <= 6 || age >= 60)
        printf ("무료입니다.");
 
    else
        printf ("1,350원 입니다.");
 
    return 0;
 }

