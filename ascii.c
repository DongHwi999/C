#include <stdio.h>


int main(void)
{
	for (int a = 32; a < 127; a++)
	{
		printf("정수%d = 문자 %c  ", a, a);
		if (a % 5 == 2) {
			printf("\n");
		}

	}

	return 0;
}

