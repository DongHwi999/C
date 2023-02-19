#include <stdio.h>
#include <string.h>

#define MAXN ((int)1e6)
#define MAXB (36)
char str[MAXN + 10];
char boom[MAXB + 10];
char sol[MAXN + 10]; // 최종 문자열 표시
int sptr; int ao;

void InputData(void) {
	scanf("%s", str);
	scanf("%s", boom);
}
void Solve(void) {
	int cnt = 0;
	int t;
	int boom_len = strlen(boom);
	for ( i = 0; str[i] ; i++) {
		sol[sptr++] = str[i]; //일단 push 하고
		if ((sptr >= boom_len) && (str[i]) == (boom[boom_len - 1])) {
			cnt = 0;
			
			int j;// 들어온게 마지막 글자하고 같으면 그 앞으로 boom 배열하고 비교	
			for (j = 1; j <= boom_len; j++) {
				if (sol[sptr - j] == boom[boom_len - j]) {
					cnt++;
				}
				else break;
			}
			if (cnt == boom_len) {
				sptr -= cnt;
			}
		}
	}
    // 출력하기전에 스택포인터 위치에 NULL문자 입력
	sol[sptr] = 0;
	return;
}
int main(void) {
	InputData();
	Solve();
	if (sptr == 0) printf("FRULA");
	else printf("%s", sol);
	return 0;
}
