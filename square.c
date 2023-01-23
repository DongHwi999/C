#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float pow(float num) {
	return num * num;
}

int main(void) {
	int a;
	float num;
	printf("정수를 입력하시오 : ");
	scanf("%f", &num);
	printf("주어진 정수 %f의 제곱은 %f입니다.", num, pow(num));
}
