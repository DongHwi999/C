#include <stdio.h>
int main(void)
{
    int i;
 
    i = 0;
    do
    {
        printf("2 x %d = %d\n", i+1, 2*(i+1));
        i = i + 1;
    }while(i < 9);
}

