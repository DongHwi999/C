#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL)); // ������ ���ڸ� �����ϱ� ���� �õ� ����
    int targetNumber = rand() % 100 + 1; // 1���� 100 ������ ���� ����
    int guess, attempts = 0;
    printf("1���� 100 ������ ���ڸ� ���ߴ� ������ �����մϴ�.\n");
    while (attempts < 10) {
        printf("������ ���ڸ� �Է��ϼ���: ");
        scanf("%d", &guess);
        if (guess < 1 || guess > 100) {
            printf("1���� 100 ������ ���ڸ� �Է��ϼ���.\n");
            continue;}

        attempts++;
        if (guess == targetNumber) {
            printf("�����մϴ�! ���� %d��(��) %d������ ���߼̽��ϴ�.\n", targetNumber, attempts);
            break;
        } else if (guess < targetNumber) {
            printf("������ ���ں��� Ů�ϴ�. ���� �õ� Ƚ��: %d\n", 10 - attempts);
        } else {
            printf("������ ���ں��� �۽��ϴ�. ���� �õ� Ƚ��: %d\n", 10 - attempts);}
    } if (attempts >= 10) {
        printf("10�� �õ� �Ŀ��� ���ڸ� ������ ���߽��ϴ�. ���� ����! ������ %d�Դϴ�.\n", targetNumber);}
    return 0;}
