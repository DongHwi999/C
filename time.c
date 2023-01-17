#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int time;
	int a;
	int b;
	int c;
	int d;
	printf("오전(0)인지 오후(1)인지 입력하세요.\n");
	scanf("%d", &time);
	
	if (time == 0) {
		printf("현재 시각을 입력하시오. n시n분\n");
		scanf("%d시 %d분", &a, &b);
		printf("계산하고 싶은 n시간 n분후를 입력하세요.\n");
		scanf("%d시간 %d분후", &c, &d);
		if (b + d >= 60 && a+c+1 > 12) {
			printf("오전 %d시 %d분에서 %d시간 %d분 후는 오후 %d시 %d분 입니다.\n", a, b, c, d, a + c -11, b + d - 60);
		}
		else if (b + d >= 60 && a+c+1<12) {
			printf("오전 %d시 %d분에서 %d시간 %d분 후는 오전 %d시 %d분 입니다.\n", a, b, c, d, a + c+1, b + d-60);
		}
		else if (b + d < 60 && a + c > 12) {
			printf("오전 %d시 %d분에서 %d시간 %d분 후는 오후 %d시 %d분 입니다.\n", a, b, c, d, a + c - 12, b + d);
		}
		else if (b + d < 60 && a + c < 12) {
			printf("오전 %d시 %d분에서 %d시간 %d분 후는 오전 %d시 %d분 입니다.\n", a, b, c, d, a + c, b + d);
		}
		else if (b + d >= 60 && a + c + 1 == 12) {
			printf("오전 %d시 %d분에서 %d시간 %d분 후는 오후 %d시 %d분 입니다.\n", a, b, c, d, a + c+1, b + d);
		}
		else if (b + d < 60 && a + c == 12) {
			printf("오전 %d시 %d분에서 %d시간 %d분 후는 오후 %d시 %d분 입니다.\n", a, b, c, d, a + c, b + d);
		}
		else {
			printf("오류");
		}
	}
	else if (time == 1){
		printf("현재 시각을 입력하시오. n시n분\n");
		scanf("%d시 %d분", &a, &b);
		printf("계산하고 싶은 n시간 n분후를 입력하세요.\n");
		scanf("%d시간 %d분후", &c, &d);
		if (b + d >= 60 && a + c + 1 > 12) {
			printf("오후 %d시 %d분에서 %d시간 %d분 후는 오전 %d시 %d분 입니다.\n", a, b, c, d, a + c - 11, b + d - 60);
		}
		else if (b + d >= 60 && a + c + 1 < 12) {
			printf("오후 %d시 %d분에서 %d시간 %d분 후는 오후 %d시 %d분 입니다.\n", a, b, c, d, a + c + 1, b + d - 60);
		}
		else if (b + d < 60 && a + c > 12) {
			printf("오후 %d시 %d분에서 %d시간 %d분 후는 오전 %d시 %d분 입니다.\n", a, b, c, d, a + c - 12, b + d);
		}
		else if (b + d < 60 && a + c < 12) {
			printf("오후 %d시 %d분에서 %d시간 %d분 후는 오후 %d시 %d분 입니다.\n", a, b, c, d, a + c, b + d);
		}
		else if (b + d >= 60 && a + c + 1 == 12) {
			printf("오후 %d시 %d분에서 %d시간 %d분 후는 오전 0시 %d분 입니다.\n", a, b, c, d, a + c + 1, b + d);
		}
		else if (b + d < 60 && a + c == 12) {
			printf("오후 %d시 %d분에서 %d시간 %d분 후는 오전 0시 %d분 입니다.\n", a, b, c, d, a + c, b + d);
		}
		else {
			printf("오류");
		}
	}
	else {
		printf("ㅋㅋ");
	}
	
	return 0;
}

