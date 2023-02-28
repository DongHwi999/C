#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int a, b, c, d;

	scanf("%d %d", &a, &b);

	c = a / 100 + ((a / 10) % 10) * 10 + ((a % 100) % 10) * 100; 
  	// ex) 123 = 1 / 100 + ((2 / 10) % 10) * 10 + ((3 % 100) % 10) * 100
	d = b / 100 + ((b / 10) % 10) * 10 + ((b % 100) % 10) * 100;

	if (c < d) {
		printf("%d", d);
	}
	else {
		printf("%d", c);
	}
}
