#include <stdio.h>

int main(void)
{
	int x, n, a, b;
	int res = 0;
	
	scanf("%d\n", &x);
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		res += a * b;
	}

	if (x == res) printf(" ¿Ç´Ù");
	else printf("Æ²¸®´Ù");

	return 0;
}
