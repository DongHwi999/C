#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparator(int left, int right){
    return left < right; // ascending
    // return left > right; // descending
}

void swap(int arr[], char strs[][40], int i, int j){

    char temp_str[40];
    strcpy(temp_str, strs[i]);
    strcpy(strs[i], strs[j]);
    strcpy(strs[j], temp_str);


    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void quick_sort(int arr[], char strs[][40], int lo, int hi){
    if (hi - lo <= 0){
        return;
    }

    int pivot = arr[lo + (hi - lo + 1) / 2];
    int i = lo, j = hi;

    while(i <= j){
        while(comparator(arr[i], pivot)) ++i;
        while(comparator(pivot, arr[j])) --j;

        if (i > j){
            break;
        }

        swap(arr, strs, i, j);        

        i++;
        j--;
    }

    quick_sort(arr, strs, lo, j);
    quick_sort(arr, strs, i, hi);
}

int main(void) {

    int arr[13];
    char strs[13][40];
	int i;
    for(i=0; i < 10; ++i){
        arr[i] = rand() % 100;
    }

    strcpy(strs[0], "01");
    strcpy(strs[1], "02");
    strcpy(strs[2], "03");
    strcpy(strs[3], "04");
    strcpy(strs[4], "05");
    strcpy(strs[5], "06");
    strcpy(strs[6], "07");
    strcpy(strs[7], "08");
    strcpy(strs[8], "09");
    strcpy(strs[9], "10");
	
    for( i = 0; i < 10; ++i){
        printf("%d %s\n", arr[i], strs[i]);
    }

    printf("\n\n");

    quick_sort(arr, strs, 0, 9);

   for(int printf("%d %s\n", arr[i], strs[i]);
    }
    
}

