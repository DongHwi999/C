#include <stdio.h>
#include <stdlib.h>

//비교 수행하는 함수, qsort의 4번째 인자
int compare(const void* arg1, const void* arg2) {
    int a = *(int*)arg1;    //void를 int형으로 변환
    int b = *(int*)arg2;
    int c;

    if (a < b) return 1;    //내림차순 정렬
    else if (a > b) return -1;
    else return 0;
}

int main(void)
{
    int arr[1000] = { 0 };
    int sizeOfArr = sizeof(arr) / sizeof(int);  //배열의 크기
    int n, k, x;

    scanf("%d%d", &n, &k);
    int i;
    for (i = 0; i < n; i++) {   //학생의 수만큼 반복
        scanf("%d", &arr[i]);
    }

    qsort(arr, sizeof(arr) / sizeof(int), sizeof(int), compare);  //정렬
    printf("%d", arr[k - 1]);   //배열은 0부터 시작하므로 1 빼서 출력
    

    return 0;
}
