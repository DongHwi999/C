#include <stdio.h>

// define�� ��ó�����̹Ƿ� main�ۿ� ����� (��ũ�� ���)
#define PI 3.141592 
#define COL 100 
#define ROW 200 

void main()
{
    // const ���
    // ����� �ݵ�� ����� �ʱ�ȭ�� ���ÿ� �ؾ� �Ѵ�.
    // �Ϲ������� ����� �빮�ڷ� ����
    const int WIDTH = 100;
    const int HEIGHT = 150;
    
    printf("WIDTH : %d\n", WIDTH);
    printf("HEIGHT : %d\n", HEIGHT);
    printf("PI : %lf\n", PI);
    
    printf("COL : %d\n", COL);
    printf("ROW : %d\n", ROW);
}
