#include <stdio.h>
#include <stdbool.h> // boolean 이용
 
// 1. n을 입력했을 때, d(n)을 구하는 함수를 작성한다.
int find_dn(int n){
    int dn = n;
    while(n>0){
        dn = dn + n%10;
        n = n/10;

    }
    return dn;
}
 
// 2. 1부터 10000까지 진행하며, d(n)들의 배열 arr_dn을 만든다.
int main(void){
	int a;
    int arr_dn[10000];
    for(int i=0; i<10000; i++){
        arr_dn[i] = find_dn(i+1);
    }
 
// 3. 1부터 10000까지의 수들 중, arr_dn에 포함되지 않는 수들을 출력한다.
    for(int num=1; num<=10000; num++){
        bool self_num = true;
        for(int j=0; j<10000; j++){
            if(num==arr_dn[j]){
                self_num = false;
            }
        }
        if(self_num)
            printf("%d\n", num);
    }
}
