#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int time;
	int a;
	int b;
	int c;
	int d;
	printf("����(0)���� ����(1)���� �Է��ϼ���.\n");
	scanf("%d", &time);
	
	if (time == 0) {
		printf("���� �ð��� �Է��Ͻÿ�. n��n��\n");
		scanf("%d�� %d��", &a, &b);
		printf("����ϰ� ���� n�ð� n���ĸ� �Է��ϼ���.\n");
		scanf("%d�ð� %d����", &c, &d);
		if (b + d >= 60 && a+c+1 > 12) {
			printf("���� %d�� %d�п��� %d�ð� %d�� �Ĵ� ���� %d�� %d�� �Դϴ�.\n", a, b, c, d, a + c -11, b + d - 60);
		}
		else if (b + d >= 60 && a+c+1<12) {
			printf("���� %d�� %d�п��� %d�ð� %d�� �Ĵ� ���� %d�� %d�� �Դϴ�.\n", a, b, c, d, a + c+1, b + d-60);
		}
		else if (b + d < 60 && a + c > 12) {
			printf("���� %d�� %d�п��� %d�ð� %d�� �Ĵ� ���� %d�� %d�� �Դϴ�.\n", a, b, c, d, a + c - 12, b + d);
		}
		else if (b + d < 60 && a + c < 12) {
			printf("���� %d�� %d�п��� %d�ð� %d�� �Ĵ� ���� %d�� %d�� �Դϴ�.\n", a, b, c, d, a + c, b + d);
		}
		else if (b + d >= 60 && a + c + 1 == 12) {
			printf("���� %d�� %d�п��� %d�ð� %d�� �Ĵ� ���� %d�� %d�� �Դϴ�.\n", a, b, c, d, a + c+1, b + d);
		}
		else if (b + d < 60 && a + c == 12) {
			printf("���� %d�� %d�п��� %d�ð� %d�� �Ĵ� ���� %d�� %d�� �Դϴ�.\n", a, b, c, d, a + c, b + d);
		}
		else {
			printf("����");
		}
	}
	else if (time == 1){
		printf("���� �ð��� �Է��Ͻÿ�. n��n��\n");
		scanf("%d�� %d��", &a, &b);
		printf("����ϰ� ���� n�ð� n���ĸ� �Է��ϼ���.\n");
		scanf("%d�ð� %d����", &c, &d);
		if (b + d >= 60 && a + c + 1 > 12) {
			printf("���� %d�� %d�п��� %d�ð� %d�� �Ĵ� ���� %d�� %d�� �Դϴ�.\n", a, b, c, d, a + c - 11, b + d - 60);
		}
		else if (b + d >= 60 && a + c + 1 < 12) {
			printf("���� %d�� %d�п��� %d�ð� %d�� �Ĵ� ���� %d�� %d�� �Դϴ�.\n", a, b, c, d, a + c + 1, b + d - 60);
		}
		else if (b + d < 60 && a + c > 12) {
			printf("���� %d�� %d�п��� %d�ð� %d�� �Ĵ� ���� %d�� %d�� �Դϴ�.\n", a, b, c, d, a + c - 12, b + d);
		}
		else if (b + d < 60 && a + c < 12) {
			printf("���� %d�� %d�п��� %d�ð� %d�� �Ĵ� ���� %d�� %d�� �Դϴ�.\n", a, b, c, d, a + c, b + d);
		}
		else if (b + d >= 60 && a + c + 1 == 12) {
			printf("���� %d�� %d�п��� %d�ð� %d�� �Ĵ� ���� 0�� %d�� �Դϴ�.\n", a, b, c, d, a + c + 1, b + d);
		}
		else if (b + d < 60 && a + c == 12) {
			printf("���� %d�� %d�п��� %d�ð� %d�� �Ĵ� ���� 0�� %d�� �Դϴ�.\n", a, b, c, d, a + c, b + d);
		}
		else {
			printf("����");
		}
	}
	else {
		printf("����");
	}
	
	return 0;
}

