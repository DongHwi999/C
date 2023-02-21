#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	int i = 0, j, num, count; k;
	char stack[51];

	scanf("%d", &num);

	while (i < num) {
		scanf("%s", &stack);
		j = 0; count = 0;

		while (j < strlen(stack)) {
			if (stack[j] == '(') count++;
			else if (stack[j] == ')') count--;
			if (count < 0)
			{
				printf("NO\n");
				break;
			}
			j++;
		}
		if (count == 0)
			printf("YES\n");
		else if (count > 0)
			printf("NO\n");
		i++;
	}
}
