#include <stdio.h>
 
int Prime(int n);
 
void main()
{
    int num = 0;
    int count = 0;
 
 
 
    // ���ϴ� ���ڸ� �ް�
    printf("[*] Enter a Number : ");
    scanf_s("%d", &num);
 
 
 
    // ������ ���鼭 �Է��� ���ں��� ���� �Ҽ��� ���� ����մϴ�
    for (; count <= num; count++)
    {
        if (Prime(count))
        {
            printf("%d ", count);
        }
    }
 
    printf("\n");
}
 
 
int Prime(int n)
{
    // 1�� �Ҽ��� �ƴϹǷ� false�Դϴ�
    if (n == 1)
        return false;
 
    // 2�� 3, 5�� �Ҽ��̹Ƿ� true�Դϴ�
    else if (n == 2 || n == 3 || n == 5)
        return true;
 
    // 2 or 3 or 5�� ����� �Ҽ��� �ƴϹǷ� false�Դϴ�
    else if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
        return false;
 
    //�� ��� ���ǿ� �ɸ��� ���� ���ڴ� �Ҽ��Դϴ�
    else
        return true;
}

