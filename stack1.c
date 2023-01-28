#include <stdio.h>
#include <stdlib.h>
 
int main() {
    Int max_size = 0, menu = 0, top = 0, i = 0, data = 0;
    int *stack;
    int c;
    printf("size of stack : ");
    scanf("%d", &max_size);
 
    stack = (int*)malloc(sizeof(int) * max_size);
    for (i = 0; i < max_size; i++ ) {
        stack[i] = 0;
    }
 
    while(1) {
        printf("=====================\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. print stack\n");
        printf("4. exit\n");
        printf("=====================\n");
        printf("select a number of menu : ");
        scanf("%d", &menu);
 
        switch(menu) {
            case 1:
                if (top >= max_size) {
                    printf("overflow!! stack is full\n");
                }
                else {
                    printf("push data : ");
                    scanf("%d", &data);
                    stack[top] = data;
                    top++;
                }
                break;
            case 2:
                if (top == 0) {
                    printf("stack is empty\n");
                }
                else {
                    top--;
                    printf("pop %d at stack\n", stack[top]);
                    stack[top] = 0;
                }
                break;
            case 3:
                for(i = 0; i < max_size; i++) {
                    printf("%d ", stack[i]);
                }
                printf("\n");
                break;
            case 4:
                free(stack);
                return 0;
                //break;
        }
    }
}