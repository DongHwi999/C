#include <stdio.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}//a�� b�� ��ȯ


void SequenceSort(int *base, int n);
int main(void)
{
    int arr[10] = { 9,4,3,10,5,8,7,6,2,1 };
    SequenceSort(arr, 10);
    return 0;
}

//���� ������ ����ϱ� ���� �Լ��Դϴ�.
void ViewArr(int *arr, int n);
void SequenceSort(int *base, int n)
{
    int i, j;
    ViewArr(base, n);//���� ���� ���
    for (i = 0; i<n; i++)
    {
        for (j = i; j<n; j++)
        {
            if (base[i]>base[j])//���� ���Ұ� �� ũ��
            {
                SWAP(base[i], base[j]);//��ȯ
                ViewArr(base, n);//���� ���
            }
        }
    }
}

void ViewArr(int *arr, int n)
{
    int i = 0;
    for (i = 0; i<n; i++)
    {
        printf("%2d ", arr[i]);
    }
    printf("\n");
}
