#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float pow(float num) {
	return num * num;
}

int main(void) {
	int a;
	float num;
	printf("������ �Է��Ͻÿ� : ");
	scanf("%f", &num);
	printf("�־��� ���� %f�� ������ %f�Դϴ�.", num, pow(num));
}
