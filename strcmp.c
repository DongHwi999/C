#include <stdio.h>
#include <string.h>
int main()
{
	char str1[20]="BananaAllergyMonkey";
	char str2[20]="AppleAntTrust";
	int size=0; 
	size=strcmp(str1,str2);
	
	if(size = 1)
		printf("������ ������ str2�� �ռ��ϴ�.\n");
    else if(size = -1)
		printf("������ ������ str1�� �ռ��ϴ�.\n");
	else if(size = 0)
		printf("���� �����մϴ�\n");
	
	return 0;
}
