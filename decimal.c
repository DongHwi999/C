#include <stdio.h>
 
int main()
{
    int num, i, cnt=0;
 
 
    printf ("���ڸ� �Է��ϼ��� : ");
    scanf ("%d", &num);
 
 
    for (i=2; i<num; i++) {
            printf ("%d %% %d = %d\n",num,i,num%i);
            if (num % i == 0)
                cnt++;
    }
 
    
    if ( cnt == 0 )
        printf ("�Ҽ� �Դϴ�");
    else 
        printf ("�Ҽ��� �ƴմϴ�");
 
 
    return 0;
 }



