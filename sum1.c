#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int sum = 0;
	int i;
    for (i = 0; i <= n; i++)
    {
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
