#include <stdio.h>

int main()
{
    float num1;
    float num2;
    float num3;

    num1 = 1.0f + 0.456789f;    // 1.0�� 0.456789�� ���ؼ� num1�� ����
    num2 = 1.0f - 0.456789f;    // 1.0���� 0.456789�� ���� num2�� ����

    printf("%f\n", num1);    // 1.456789
    printf("%f\n", num2);    // 0.543211

    return 0;
}
