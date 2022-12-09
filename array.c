#include <stdio.h>
#include <stdlib.h>

int intscan(void)
{
    int n;

    printf("size of arr : ");
    scanf("%d", &n);

    return n;
}

int maxf(int* temp, int size)
{
    int max = *temp; int i;

    for(i=0;i<size;i++){
        if( *(temp+i) > max )
            max = *(temp+i);
    }

    return max;
}

int minf(int* temp, int size)
{
    int min = *temp; int i;

    for(i=0;i<size;i++){
        if( *(temp+i) < min )
            min = *(temp+i);
    }

    return min;
}

int main(void)
{
    int n = intscan(); int i; int* p = (int*)malloc(sizeof(int)*n);

    for(i=0;i<n;i++){
        printf("arr[%d] : ", i);
        scanf("%d", p+i);
    }

    printf("max(arr) : %d, min(arr) : %d", maxf(p, n), minf(p, n));

    return 0;
}
