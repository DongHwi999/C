#include <stdio.h>

int main()
{
	/*
		아래 ptr1 ~ ptr3 까지의 선언은 선언과 동시에 ptr은 각 num의 주소를 가리킴.
	*/
	int num1 = 10, num2 = 20, num3 = 30;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	int* ptr3 = &num3;

	// 배열의 내부 인자로 사용할 값의 자료형이 int* 이므로, 배열이름의 자료형은 int* 형이 되어야 함
	int* ptrArr[] = { ptr1, ptr2, ptr3 };
	/*				   
		ptrArr[0] -> ptr1 -> num1
		ptrArr[1] -> ptr2 -> num2
		ptrArr[2] -> ptr3 -> num3
		이런식의 포인터가 선언된 것임.
	*/

	// ptrArr은 기본적으로 *int 자료형이고, 앞에 선언한 자료형이 int* 이므로, ptrArr 자체는 int** 자료형임.
	int** dptr = ptrArr;
	// 배열에 포인터를 선언하여 같은 첫번째 주소값을 공유함. 포인터를 배열 처럼 사용할 수 있다.

	dp[0] = 10;
	dp[1] = 20;
	dp[2] = 30;

	printf("%d %d %d \n", dp[0], dp[1], dp[2]);

	return 0;
}
