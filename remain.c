#include <stdio.h>

int main(void) {
    
    int input, result=0;
    int remain[10];
    
    for(int i=0; i<10; i++) {
        scanf("%d", &input);
        remain[i] = (input % 42);
    }
    
    for(int i=0; i<10; i++) {
        int count=0; // �ʱ�ȭ
        for(int j=i+1; j<10; j++) { // ���� ���� ���� ���
            if(remain[i] == remain[j]) count++;
        }
        if (count == 0) result++; // ���� ���� ���� ��� ������ ���ش�
    }
    
   printf("%d", result);
}
