#include <stdio.h>
#include <Windows.h>
 
void StrCpySelfMade(char* s1, const char* s2);
 
void main()
{
    char s1[100] = "Imagine Explosion";
    char s2[100] = { 0 };
    char c;
    int count = 0;
 
    printf("( s1 ) is : [ %s ]\n",s1);
 
    printf("\n");
 
    printf("( s2 ) : ");
    for (; (c = getchar()) != '\n';)
    {
        s2[count] = c;
        count++;
    }
 
    
 
    printf("\n");
    Sleep(500);
    printf("[*] WAIT, StrCpySelfMade function is running...\n");
    Sleep(2000);
 
    printf("\n");
    
    StrCpySelfMade(s1, s2);
 
    printf("s1 : [ %s ] ,\ns2 : [ %s ] \n\n", s1, s2);
 
 
}
 
void StrCpySelfMade(char* s1, const char* s2)
{
    int i = 0;
 
    // ���ڿ��� ���� ������(\0) s2�� ���ڿ��� s1�� �����մϴ�
    for (i = 0; s2[i] != '\0'; i++)
        s1[i] = s2[i];
 
    // s2[i] = '\0'
    // s1�� �������� '\0'�� �Է��ؼ� ���ڿ��� ���� �˸��ϴ�
    s1[i] = s2[i];
 
}
