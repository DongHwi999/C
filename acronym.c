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
        if (isalpha(buffer[count]))     // buffer 값을 늘려가다가 알파벳을 발견하면
        {
            if (islower(buffer[count]))   // buffer2에 대문자 값을 입력한다
            {
                buffer2[count2] = toupper(buffer[count]);
                count2++;
            }
            else
            {
                buffer2[count2] = buffer[count];
                count2++;
            }
            for (; !isspace(buffer[count]);)  // 다음 공백이 나올 때까지 count를 증가시킨다
            {
                count++;
                if (buffer[count] == '\0')    // buffer의 끝부분에 도달하면 루프 탈출
                    break;
            }
        }
        count++;
    }
 
    printf("Acronym String is : \"%s\"\n", buffer2);
 
}
