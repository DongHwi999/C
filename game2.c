#include <stdio.h>

int main() {

	int t;
	int a[101][101] = {0,};
    int n=0, s=1, c=0, r=1, k=0;
    int i, j, kk;
    
    scanf("%d", &k);	// 가로 세로 크기 
    
    kk=k;
    
	while(k) {
	    for(i=1; i<=k; i++) {
	        n=n+1;
	        c=c+s;
	        a[r][c] = n;
	    }
	    
		k=k-1;

	    for(i=1; i<=k; i++) {
	        n=n+1;
	        r=r+s;
	        a[r][c] = n;
	    }
	    
	   s=s*(-1); // -S
	}

    // 배열 내용 출력 하 기 
    for(int i=1; i<=kk; i++, puts(""))
        for(int j=1; j<=kk; j++)
            printf("%3d", a[i][j]);
           
	return 0;
}
