#include <stdio.h>
#include <string.h>
 
int top;
 
//������ push, pop ���� �Լ�
void push(char a[], char c) {
	a[++top] = c;
}
 
char pop(char a[]) {
	char c = a[top];
	a[top--] = '\0'; //���ڿ� ������ ���ϱ� ���� pop�� �ڸ��� ���鹮�ڷ� ġȯ
	return c;
}
 
int main(void) {
 
	while (1) {
		int flag = 0;
		char c;
		char input[101] = " "; //���� ���ڿ� ���� �迭
		char check[101] = " "; //�񱳸� ���� �迭
		top = -1;
 
		while (1) {
        	//�ٹٲ� ������ char�� input ���ÿ� push
			c = getchar(); 
			if (c == '\n') break; 
			push(input, c);
		}
		if (strcmp(".", input) == 0) break; // �Է°��� . �ϳ����̸� ���α׷� ����
 
		top = -1; //���� �ʱ�ȭ
        //���ڿ� ���̸�ŭ for�� ������. -1�� ���ִ� ������ ���ڿ��� .�� ���ԵǾ� �ֱ� ����
		for (int i = 0; i < strlen(input)-1; i++) { 
			c = input[i];
            
			//���ڿ��� [ �Ǵ� (�̸� push
			if (c == '[') 
				push(check, c);
 
			else if (c == '(') 
				push(check, c);
			
            //���ڿ��� ) �Ǵ� ]�̸� ������ ž�� ���Ͽ� ¦�� �̷���� üũ
            //¦�� �̷��� ������ flag���� �� �ٲ��� �� for�� ������, ¦�� ��� pop
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
			if (top!=-1) flag = 1; //���ÿ� ���� ���ڰ� ���� ��� flag���� �� �ٲ��ֱ�
			printf("%s\n", (flag == 0) ? "yes" : "no");
	}
	return 0;
}
