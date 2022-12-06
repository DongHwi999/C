#include <stdio.h>
#include <string.h>
int main(void)
{
    //1. ���ڿ� ���� �⺻ ����
    const char* name = "BlockDMask";
    printf("1. const char* name = \"BlockDMask\"");
    printf("\tlen : %d\n",  (int)strlen(name));    //strlen(const char*)
    
    //2. �迭�� ũ��� ���ڿ��� ���̴� �ٸ��ϴ�.
    char arr1[50] = "BlockDMask";
    printf("2. char arr1[50]  = \"BlockDMask\"");
    printf("\tlen : %d\n", (int)strlen(arr1));    //strlen(char arr[ ])
 
    //3. �߰��� '\0'�� �����Ҷ��� strlen�� ��ȯ
    char arr2[100] = "Block\0DMask";    //�迭�� ũ���, ���ڿ��� ���̴� �ٸ��ϴ�.22
    printf("3. char arr2[100] = \"Block\\0DMask\"");
    printf("\tlen : %d\n", (int)strlen(arr2));    //strlen(char arr[ ])
 
    return 0;
}
