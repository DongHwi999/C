#include<stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int arrCopy[100], i = left, j = mid+1, k = left;
    while(i<=mid && j<=right) {
        if(arr[i] <= arr[j]) arrCopy[k++] = arr[i++];
        else arrCopy[k++] = arr[j++];
    }
    while(i<=mid) arrCopy[k++] = arr[i++];
    while(j<=right) arrCopy[k++] = arr[j++];
    int a;
    for(a=left; a<=right; a++) arr[a] = arrCopy[a];
}

void mergeSort(int arr[], int left, int right) {
    int mid;
    if(left < right) {
        mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[100], n;
    scanf("%d", &n);
    int i;
    for(i=0; i<n; i++) scanf("%d", &arr[i]);

    mergeSort(arr, 0, n-1);

    for(i=0; i<n; i++) printf("%d ", arr[i]);
}
