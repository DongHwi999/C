#include <stdio.h>
 
int main(){
    int N,x=1, cnt=1;
    int k;
    scanf("%d",&N);
    
    //���ѷ���
    while(1){
        //N�� ������ ������ �� ���� �۰ų� ���� ���
        if(N-x<=0) break;
        
        //cnt��°�� ������ ���� ���� ����
        N-=x;
        
        //���� ��°�� �����Ǵ� ���� ���� ���
          x=cnt*6;
        
        //cnt����
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}

