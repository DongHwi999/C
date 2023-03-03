#include <stdio.h>
#include <string.h>
 
int top;
 
//스택의 push, pop 연산 함수
void push(char a[], char c) {
	a[++top] = c;
}
 
char pop(char a[]) {
	char c = a[top];
	a[top--] = '\0'; //문자열 오류를 피하기 위해 pop한 자리를 공백문자로 치환
	return c;
}
 
int main(void) {
 
	while (1) {
		int flag = 0;
		char c;
		char input[101] = " "; //원본 문자열 저장 배열
		char check[101] = " "; //비교를 위한 배열
		top = -1;
 
		while (1) {
        	//줄바꿈 전까지 char를 input 스택에 push
			c = getchar(); 
			if (c == '\n') break; 
			push(input, c);
		}
		if (strcmp(".", input) == 0) break; // 입력값이 . 하나뿐이면 프로그램 종료
 
		top = -1; //스택 초기화
        //문자열 길이만큼 for문 돌리기. -1을 해주는 이유는 문자열에 .이 포함되어 있기 때문
		for (int i = 0; i < strlen(input)-1; i++) { 
			c = input[i];
            
			//문자열이 [ 또는 (이면 push
			if (c == '[') 
				push(check, c);
 
			else if (c == '(') 
				push(check, c);
			
            //문자열이 ) 또는 ]이면 스택의 탑과 비교하여 짝을 이루는지 체크
            //짝을 이루지 않으면 flag변수 값 바꿔준 후 for문 나가고, 짝일 경우 pop
			else if (c == ')') {
				if (check[top] != '(') {
					flag = 1;
					break;
				}
				pop(check);
			}
			else if (c == ']') {
				if (check[top] != '[') {
					flag = 1;
					break;
				}
				pop(check);
			}	
		}	
			if (top!=-1) flag = 1; //스택에 남은 문자가 있을 경우 flag변수 값 바꿔주기
			printf("%s\n", (flag == 0) ? "yes" : "no");
	}
	return 0;
}
