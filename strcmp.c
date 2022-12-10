#include <stdio.h>
#include <string.h>
int main()
{
	char str1[20]="BananaAllergyMonkey";
	char str2[20]="AppleAntTrust";
	int size=0; 
	size=strcmp(str1,str2);
	
	if(size = 1)
		printf("사전적 순서는 str2이 앞섭니다.\n");
    else if(size = -1)
		printf("사전적 순서는 str1이 앞섭니다.\n");
	else if(size = 0)
		printf("둘은 동일합니다\n");
	
	return 0;
}
