#include <stdio.h>

int main()
{
	/*
		�Ʒ� ptr1 ~ ptr3 ������ ������ ����� ���ÿ� ptr�� �� num�� �ּҸ� ����Ŵ.
	*/
	int num1 = 10, num2 = 20, num3 = 30;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	int* ptr3 = &num3;

	// �迭�� ���� ���ڷ� ����� ���� �ڷ����� int* �̹Ƿ�, �迭�̸��� �ڷ����� int* ���� �Ǿ�� ��
	int* ptrArr[] = { ptr1, ptr2, ptr3 };
	/*				   
		ptrArr[0] -> ptr1 -> num1
		ptrArr[1] -> ptr2 -> num2
		ptrArr[2] -> ptr3 -> num3
		�̷����� �����Ͱ� ����� ����.
	*/

	// ptrArr�� �⺻������ *int �ڷ����̰�, �տ� ������ �ڷ����� int* �̹Ƿ�, ptrArr ��ü�� int** �ڷ�����.
	int** dptr = ptrArr;
	// �迭�� �����͸� �����Ͽ� ���� ù��° �ּҰ��� ������. �����͸� �迭 ó�� ����� �� �ִ�.

	dp[0] = 10;
	dp[1] = 20;
	dp[2] = 30;

	printf("%d %d %d \n", dp[0], dp[1], dp[2]);

	return 0;
}
