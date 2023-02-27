#include <stdio.h>
#include <stdbool.h> // boolean �̿�
 
// 1. n�� �Է����� ��, d(n)�� ���ϴ� �Լ��� �ۼ��Ѵ�.
int find_dn(int n){
    int dn = n;
    while(n>0){
        dn = dn + n%10;
        n = n/10;

    }
    return dn;
}
 
// 2. 1���� 10000���� �����ϸ�, d(n)���� �迭 arr_dn�� �����.
int main(void){
	int a;
    int arr_dn[10000];
    for(int i=0; i<10000; i++){
        arr_dn[i] = find_dn(i+1);
    }
 
// 3. 1���� 10000������ ���� ��, arr_dn�� ���Ե��� �ʴ� ������ ����Ѵ�.
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
