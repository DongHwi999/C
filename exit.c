#include <stdlib.h>

#include <stdio.h>

 

void EndFunc(void);

int main(void)

{

    int i;
	int k;
 

    _set_abort_behavior( 0, _WRITE_ABORT_MSG);//abort �Լ� ȣ���Ͽ��� �� ���� â ���� �ʰ� ����   

    atexit(EndFunc);//���α׷� ������ �� ������ EndFunc �Լ� ���

 

    printf("1�� �Է��ϸ� ���� ����\n");

    scanf_s("%d",&i);

 

    if(i==1)

    {

        exit(0);//���� ����

    }

    abort();//������ ����

    printf("Here is main\n");//�������� ����

 

    return 0;

}

void EndFunc(void)

{

    printf("Here is EndFunc\n");

}
