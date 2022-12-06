#include <stdio.h>
#include <string.h>
int main(void)
{
    //1. 문자열 길이 기본 예제
    const char* name = "BlockDMask";
    printf("1. const char* name = \"BlockDMask\"");
    printf("\tlen : %d\n",  (int)strlen(name));    //strlen(const char*)
    
    //2. 배열의 크기와 문자열의 길이는 다릅니다.
    char arr1[50] = "BlockDMask";
    printf("2. char arr1[50]  = \"BlockDMask\"");
    printf("\tlen : %d\n", (int)strlen(arr1));    //strlen(char arr[ ])
 
    //3. 중간에 '\0'가 존재할때의 strlen의 반환
    char arr2[100] = "Block\0DMask";    //배열의 크기와, 문자열의 길이는 다릅니다.22
    printf("3. char arr2[100] = \"Block\\0DMask\"");
    printf("\tlen : %d\n", (int)strlen(arr2));    //strlen(char arr[ ])
 
    return 0;
}
