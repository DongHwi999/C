#include<stdio.h>
#include<string.h>
#include<Windows.h>

int main() {
	printf("문자를 입력하시오 : ");
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
		printf("모음입니다.");
	}
	else {
		printf("자음입니다.");
	}
	system("pause");
	return 0;
}
