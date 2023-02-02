#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	clock_t start, end;
	float res;
	start = clock();
	int sum = 0;
	int i;
	int t;
	for (i = 0; i < 100000000; i++)
	{
		sum += i;
	}
	printf("더한 값 : %d \n", sum);

	end = clock();
	res = (float)(end - start) / CLOCKS_PER_SEC;

	printf("\n소요시간 : %.3f \n", res);
	return;
}
