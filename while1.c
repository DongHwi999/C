#include <stdio.h>
 
int main()
{
    char c;     // �Է¹��� ��
    while(1)    // ���ѷ���
    {
        scanf("%c", &c);    // �� �Է�
        printf("%c", c);    // ���
        if(c == 'q')        // �Է¹��� ���ڰ� q���
            break;          // �ݺ��� ���� 
    }
    return 0;
}

