#include <stdio.h>

int main() {
	char a[16];
	scanf("%s", &a);

	int ret = 0;

	int i = 0;
	while (a[i]) {
		ret += (a[i] - 'A') / 3 + 3;
		if (a[i] == 'S' || a[i] == 'V' || a[i] == 'Y' || a[i] == 'Z') ret -= 1;
		++i;
	}

	printf("%d\n", ret);

	return 0;
}

