#include <stdio.h>

int main()

{
	int n, k, arr[5000], arr2[5000], cnt = 0, a = 0, b, index=0, check;
	scanf_s("%d %d", &n, &k);
	int i;
	for (i = 0; i < n; i++)
	arr[i] = i + 1;
 	while (1) {
 		b = a % n;
 	if (arr[b] != 0) {
 		cnt++;
 		check = 0;
 	}
	else
	check = 1;

	if (cnt%k==0&&check==0) {
		arr2[index] = arr[b];
		index++;
		arr[b] = 0;
	}
	a++;
	if (index == n)
	break;
	}
	if (n == 1)
	printf("<%d>", arr2[0]);

	else {
	printf("<%d, ", arr2[0]);
	int i;
	for (i = 1; i < n - 1; i++)
	printf("%d, ", arr2[i]);
	printf("%d>", arr2[n - 1]);
	}
}
