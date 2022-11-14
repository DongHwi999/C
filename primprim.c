#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000 

typedef struct GraphType{
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

int get_min_vertex(int n){
    int v,i;
    for(i=0;i<n;i++){
        if(!selected[i]){
            v=i;
            break;
        }
    }
    for(i=0; i<n;i++)
        if(!selected[i]&&(distance[i]<distance[v])) v=i;
    return (v);
}

void print_status(GraphType* g){
    static int step = 1;
    printf("distance[]: ");
    for (int i=0;i<g->n;i++){
        if(distance[i] == INF)
            printf(" 1000 ");
        else
            printf(" %2d",distance[i]);
    }
    printf("\n");
    printf("selected[]: ");
    for(int i=0;i<g->n;i++)
        printf(" %2d",selected[i]);
    printf("\n\n");
}

void prim(GraphType* g,int s)
{
    int i,v,u;

    for(u=0;u<g->n;u++)
        distance[u] = INF;
    distance[s] = 0;
    for(i=0;i<g->n;i++){
        u=get_min_vertex(g->n);
        selected[u] = TRUE;
        if(distance[u]==INF)return;
        printf("정점 %d 추가\n",u);
        print_status(g);
        for(v=0;v<g->n;v++)
            if(g->weight[u][v] != INF)
                if(!selected[v] && g->weight[u][v]<distance[v])
                    distance[v] = g->weight[u][v];
    }
}


int main(void){
    GraphType g = {7,
    {{0,29,INF,INF,INF,10,INF},
    {29,0,16,INF,INF,INF,15},
    {INF,16,0,12,INF,INF,INF},
    {INF,INF,12,0,22,INF,18},
    {INF,INF,INF,22,0,27,25},
    {10,INF,INF,INF,27,0,INF},
    {INF,15,INF,18,25,INF,0}}
    };
    prim(&g,0);
    return 0;
}
