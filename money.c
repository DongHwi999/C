#include <stdio.h>

int tax(int salary); // �Լ����� function(�Ű�����1,�Ű�����2...) 

int main()
{
	double sal=0; //���� ������ ���ɾ� 
	double result=0;
	printf("���� ���ɾ��� �Է��Ͻÿ� >> ");
	scanf("%lf", &sal);
	
	result=tax(sal);
	
	printf("�̹� �� ���� �Ǽ��ɾ��� %.0lf�� �Դϴ� ", result);

    return 0;
}
int tax(int salary)
{
	double result=0;
	result = salary-(salary * 0.045);
	return result; 
}
