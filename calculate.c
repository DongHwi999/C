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
	printf("���ϴ� �� ���� �Է��Ͻÿ� >> ");
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
	printf("���ϴ� �޴��� �Է��Ͻÿ�>> (1.���ϱ�2.����3.����4.������))\n");
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
