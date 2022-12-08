#include <stdio.h>

void print_menu();
double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double div(double a, double b);

int main()
{
	double num1, num2=0;
	int chs=0;
	double result=0;
	print_menu();
	scanf("%d", &chs);
	printf("원하는 두 수를 입력하시오 >> ");
	scanf("%lf%lf", &num1, &num2);
	
	switch(chs)
	{
		case 1:
			result=add(num1,num2);
			printf("result : %.0lf",result);
			break;
		case 2:
			result=sub(num1,num2);
			printf("result : %.0lf",result);
			break;
		case 3:
			result=mul(num1,num2);
			printf("result : %.0lf",result);
			break;
		case 4:
			result=div(num1,num2);
			printf("result : %.6lf",result);
			break;	
	}
    return 0;
}

void print_menu()
{
	printf("----------------------\n");
	printf("원하는 메뉴를 입력하시오>> (1.더하기2.뺄셈3.곱셈4.나눗셈))\n");
	printf("----------------------\n");
}
double add(double a, double b)
{
	return a+b;
}
double sub(double a, double b)
{
	return a-b;
}
double mul(double a, double b)
{
	return a*b;
}
double div(double a, double b)
{
	return a/b;
}
