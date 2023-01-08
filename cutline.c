#include <stdio.h>
#include <stdlib.h>

//�� �����ϴ� �Լ�, qsort�� 4��° ����
int compare(const void* arg1, const void* arg2) {
    int a = *(int*)arg1;    //void�� int������ ��ȯ
    int b = *(int*)arg2;
    int c;

    if (a < b) return 1;    //�������� ����
    else if (a > b) return -1;
    else return 0;
}

int main(void)
{
    int arr[1000] = { 0 };
    int sizeOfArr = sizeof(arr) / sizeof(int);  //�迭�� ũ��
    int n, k, x;

    scanf("%d%d", &n, &k);
    int i;
    for (i = 0; i < n; i++) {   //�л��� ����ŭ �ݺ�
        scanf("%d", &arr[i]);
    }

    qsort(arr, sizeof(arr) / sizeof(int), sizeof(int), compare);  //����
    printf("%d", arr[k - 1]);   //�迭�� 0���� �����ϹǷ� 1 ���� ���
    

    return 0;
}
