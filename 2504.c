#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int len, i, flag=0,j;
	int numofArr = 0, numofSum = 0, sum = 0;
	int arr[30] = { 0, };
	int sumArr[30];
	char str[31];
	scanf("%s", str);
	len = strlen(str);
	for (i = 0; i < len; i++) {
		if (str[i] == '(') {
			arr[numofArr] = 2;
			numofArr++;
		}
		else if (str[i] == '[') {
			arr[numofArr] = 3;
			numofArr++;
		}
		else if (str[i] == ')') {
			if (numofArr == 0) {
				printf("0");
				return 0;
			}
			if (arr[numofArr - 1] != 2) {
				printf("0");
				return 0;
			}
			else {
				arr[numofArr - 1] = 0;
				numofArr--;
			}
		}
		else if (str[i] == ']') {
			if (numofArr == 0) {
				printf("0");
				return 0;
			}
			if (arr[numofArr - 1] != 3) {
				printf("0");
				return 0;
			}
			else {
				arr[numofArr - 1] = 0;
				numofArr--;
			}
		}
	}
	if (numofArr != 0) {
		printf("0");
		return 0;
	}
	for (i = 0; i < len; i++) {
		if (str[i] == '(') {
			arr[numofArr] = 2;
			numofArr++;
			flag = 1;
		}
		else if (str[i] == '[') {
			arr[numofArr] = 3;
			numofArr++;
			flag = 1;
		}
		else if (str[i] == ')') {
			if (flag) {
				sumArr[numofSum] = 1;
				for (j = 0; j < numofArr; j++) {
					sumArr[numofSum] *= arr[j];
				}
				numofSum++;
			}
			arr[numofArr - 1] = 0;
			numofArr--;
			flag = 0;
		}
		else if (str[i] == ']') {
			if (flag) {
				sumArr[numofSum] = 1;
				for (j = 0; j < numofArr; j++) {
					sumArr[numofSum] *= arr[j];
				}
				numofSum++;
			}
			arr[numofArr - 1] = 0;
			numofArr--;
			flag = 0;
		}
	}
	for (i = 0; i < numofSum; i++) {
		sum += sumArr[i];
	}
	printf("%d", sum);
	return 0;
}
