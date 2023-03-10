#include <stdio.h>

int main()
{
    int student[31] = {0,};
    int num;

    for(int i=1; i<=28; i++){
        scanf("%d", &num);
        student[num] = 1;
    }

    for(int j=1; j<=30; j++){
        if(student[j] == 0) {
            printf("%d\n", j);
        }
    }
    return 0;
}
