#include <stdio.h>
 
int Prime(int n);
 
void main()
{
    int num = 0;
    int count = 0;
 
 
 
    // 원하는 숫자를 받고
    printf("[*] Enter a Number : ");
    scanf_s("%d", &num);
 
 
 
    // 루프를 돌면서 입력한 숫자보다 작은 소수를 전부 출력합니다
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
    // 1은 소수가 아니므로 false입니다
    if (n == 1)
        return false;
 
    // 2와 3, 5는 소수이므로 true입니다
    else if (n == 2 || n == 3 || n == 5)
        return true;
 
    // 2 or 3 or 5의 배수는 소수가 아니므로 false입니다
    else if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
        return false;
 
    //위 모든 조건에 걸리지 않은 숫자는 소수입니다
    else
        return true;
}

