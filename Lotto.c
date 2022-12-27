#include <stdio.h>
int arr[14];
int arr2[14];
int K;
void DFS(int Start,int Depth)
{
    int i;
    if (Depth == 6)
    {
        for (i = 0; i < 6; i++)
        {
            printf("%d ", arr2[i]);
        }
        printf("\n");
    }
    else
    {
        for (i = Start; i < K; i++)
        {
            arr2[Depth] = arr[i];
            DFS(i + 1, Depth + 1);
        }
        
    }
}
 
int main()
{
    int i;
    
    while (1)
    {
        scanf("%d", &K);
        if (K == 0)
            break;
        for (i = 0; i < K; i++)
            scanf("%d", &arr[i]);
        DFS(0, 0);
        printf("\n");
    }
}    
