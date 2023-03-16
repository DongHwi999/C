#include <stdio.h>

int main(void)
{
	int n, i, j;
    	int han = 99, ch1, ch2;
	scanf("%d", &n);

	if (n < 100)
	{
		printf("%d", n);
		return 0;
	}

	for (i = 100; i <= n; i++)
	{
		ch1 = i / 100 - i / 10 % 10;     //백의 자릿수와 십의 자릿수의 수 차이
		ch2 = i / 10 % 10 - i % 10;      //십의 자릿수와 일의 자릿수의 수 차이
        
		if (ch1 == ch2)
			han++;
	}

	printf("%d\n", han);
	return 0;
}
