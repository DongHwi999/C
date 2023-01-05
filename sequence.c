#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	// 수열 만들기
	int nums[1000];
	
	int cnt = 0;
	int i;
	for (int i = 0; i < 1000; i++)
	{
		int j;
		for (int j = 0; j < i; j++)
		{
			if (cnt == 1000)
				break;

			nums[cnt] = i;
			cnt++;
		}
	}
	int st, end;
	scanf("%d %d", &st, &end);
	int result = 0;
	for (int i = st - 1; i < end; i++)
	{
		result += nums[i];
	}
	printf("%d\n", result);
}
