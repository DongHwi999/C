#include <stdio.h>
#include <stdlib.h>
#define SWAP(a,b) {int t; t=a; a=b; b=t;}
// 배열의 크기
int n;
void PrintSit(int list[], int high, int low)
{
	int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", list[i]);
    }
    printf("\n");
    
    for (i = 0; i < n; i++)
    {
        if (i == high)
            printf("high\t");
        else if (i == low)
            printf("low\t");
        else
            printf("\t");
    }
    printf("\n");
}
int partition(int list[], int left, int right)
{
    int pivot;
    int low, high;
    low = left;
    high = right + 1;
    pivot = list[left];
    do
    {
        do
        {
            low++;
        } while (low <= right && list[low] < pivot);
        do
        {
            high--;
        } while (high >= left && list[high] > pivot);
        if (low < high)
        {
            PrintSit(list, high, low);
            SWAP(list[low], list[high]);
        }
        if (low+1 >= high)
            PrintSit(list, high, low);
    } while (low < high);
    SWAP(list[left], list[high]);
    return high;
}
void QuickSort(int list[], int left, int right)
{
    if (left < right)
    {
        int q = partition(list, left, right);
        QuickSort(list, left, q - 1);
        QuickSort(list, q + 1, right);
    }
}
int main(void)
{
    int ar[8] = {67,90,57,25,84,32,73,54};
    n=8;    
    QuickSort(ar, 0, n - 1);   
    return 0;
}

