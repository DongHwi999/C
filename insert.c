#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define NAME_SIZE 100

typedef struct
{
    int key;
    char name[NAME_SIZE];
} record;
record list[MAX_SIZE];

void insertion_sort(record list[], int n)
{
    int i, j;
    record key_record;
    for (i = 1; i < n; i++) 
    {
        key_record = list[i];
        for (j = i - 1; j >= 0 && list[j].key > key_record.key; j--)
            list[j + 1] = list[j]; 		// 레코드의 오른쪽 이동
        list[j + 1] = key_record;
    }
}

int main()
{
	return 0;
}
