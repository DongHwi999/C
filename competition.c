#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str1[1001] = { 0 };
char str2[1001][1001] = { 0 };
char temp[1001] = { 0 };

int main()
{
	int len;

	scanf("%s", str1);
	len = strlen(str1);


	for (int i = 0; i < len; i++) // 접미사 저장
	{
		for (int j = i; j < len; j++)
		{
			str2[i][j-i] = str1[j];
		}
	}

	for (int i = 0; i < len - 1; i++) // 버블 정렬
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (strcmp(str2[j], str2[j+1]) > 0)
			{
				strcpy(temp, str2[j]);
				strcpy(str2[j], str2[j + 1]);
				strcpy(str2[j + 1], temp);
			}
		}
	}

	for (int i = 0; i < len; i++)
		printf("%s\n", str2[i]);
		printf("strcmp 함수");


	return 0;
}
