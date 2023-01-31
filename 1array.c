#include <stdio.h>
 
int main(void){
    int N;
    scanf("%d", &N);
 	int a;
 	
    int arr[N];
    int i;
    for(i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
 
    int v;
    scanf("%d", &v);
 
    int count = 0;
    int j;
    for( j=0; j<N; j++){
        if(arr[j]==v)
            count++;
    }
    printf("%d\n", count);
}
