#include<stdio.h>
#include<string.h>
#include<Windows.h>

int main() {
	printf("���ڸ� �Է��Ͻÿ� : ");
	char alphabat;
	char str[11] = "aeiouAEIOU";
	int a;
	scanf_s("%c", &alphabat);


	int cnt = 0;
	int i;
	for (i = 0; i < 10; i++) {
		if (alphabat == str[i]) {
			cnt = 1;
			break;
		}			
	}

	if (cnt == 1) {
		printf("�����Դϴ�.");
	}
	else {
		printf("�����Դϴ�.");
	}
	system("pause");
	return 0;
}
