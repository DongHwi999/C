#include <stdio.h>
#include <stdlib.h>

int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (low <= right && list[low] < pivot);
		do
			high--;
		while (high >= left && list[high] > pivot);
		
		for (int i = 0; i < n; i++) // 패스 과정 출력
			printf("%d ", list[i]);
		printf("\nlow=%d, high=%d\n", low, high);

		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}

