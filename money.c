#include <stdio.h>

int tax(int salary); // 함수선언 function(매개변수1,매개변수2...) 

int main()
{
	double sal=0; //월급 공제전 수령액 
	double result=0;
	printf("월급 수령액을 입력하시오 >> ");
	scanf("%lf", &sal);
	
	result=tax(sal);
	
	printf("이번 달 월급 실수령액은 %.0lf원 입니다 ", result);

    return 0;
}
int tax(int salary)
{
	double result=0;
	result = salary-(salary * 0.045);
	return result; 
}
