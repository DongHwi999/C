#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

char S[100001];
char stack[100001];
char answer[100001];

int main() {
	int i, top = -1;
	scanf("%[^\n]", &S);
	int len = strlen(S);
	for (i = 0; i < len; i++) {
		if (S[i] == '<') {
			while (top != -1) {
				answer[i - top - 1] = stack[top];
				top--;
			}
			while (S[i] != '>') {
				answer[i] = S[i];
				i++;
			}
			answer[i] = S[i];
		}
		else if (S[i] == ' ') {
			while (top != -1) {
				answer[i - top - 1] = stack[top];
				top--;
			}
			answer[i] = S[i];
		}
		else {
			top++;
			stack[top] = S[i];
		}
	}
	while (top != -1) {
		answer[i - top - 1] = stack[top];
		top--;
	}
	printf("%s", answer);
	return 0;
}
