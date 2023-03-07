#include <stdio.h>

int main()
{
    int num1;
    int num2;
    int money;
    int q,p;
    scanf("%d",&num1);
    for (int i = 0; i < num1; i++)
    {
        scanf("%d",&money);
        scanf("%d",&num2);
        
        if(num2 !=0)
        {
            for (int i = 0; i < num2; i++)
            {
                scanf("%d %d",&q,&p);
                money = money + q * p;
            }
        }
        printf("%d\n",money);
    }
    return 0;
}
