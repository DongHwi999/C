#include <stdio.h>
#include <Windows.h>
 
void main()
{
    char c;
    char buffer[100] = { 0 };
    char buffer2[100] = { 0 };
    int count = 0;
    int count2 = 0;
 
    printf("Enter a string want to be acronym : ");
    while (1)
    {
        for (; (c = getchar()) != '\n';)
        {
            buffer[count] = c;
            count++;
        }
        break;
    }
 
    count = 0;
 
    while (buffer[count] != '\0')   
    {
        if (isalpha(buffer[count]))     // buffer ���� �÷����ٰ� ���ĺ��� �߰��ϸ�
        {
            if (islower(buffer[count]))   // buffer2�� �빮�� ���� �Է��Ѵ�
            {
                buffer2[count2] = toupper(buffer[count]);
                count2++;
            }
            else
            {
                buffer2[count2] = buffer[count];
                count2++;
            }
            for (; !isspace(buffer[count]);)  // ���� ������ ���� ������ count�� ������Ų��
            {
                count++;
                if (buffer[count] == '\0')    // buffer�� ���κп� �����ϸ� ���� Ż��
                    break;
            }
        }
        count++;
    }
 
    printf("Acronym String is : \"%s\"\n", buffer2);
 
}
