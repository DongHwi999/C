#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES	100	
#define INF	50000	/* ���Ѵ� (������ ���� ���) */

typedef struct GraphType {
	int n;	// ������ ����
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];/* �����������κ����� �ִܰ�� �Ÿ� */
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i<n; i++)
		if (distance[i]< min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}
void print_status(GraphType* g)
{
//	printf("%s", GraphType g);
	static int step=1;
	printf("distance: ");
    for (int i = 0; i < g->n; i++) {
        
        if (distance[i] == INF)
            printf(" * ");
        else
            printf("%2d ", distance[i]);
    }
    
    //static int step=1;
    
	printf("STEP %d: ", step++);
	
	for (int i = 0; i<g->n; i++)
    // int found[i][0]=1;
    printf("%2d ", found[i]);
    printf("\n");
    
}
    

void shortest_path(GraphType* g, int start)
{
	int i, u, w;
	for (i = 0; i<g->n; i++) /* �ʱ�ȭ */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;    /* ���� ���� �湮 ǥ�� */
	distance[start] = 0;
	for (i = 0; i<g->n-1; i++) {
		print_status(g);
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w<g->n; w++)
			if (!found[w])
				if (distance[u] + g->weight[u][w]<distance[w])
					distance[w] = distance[u] + g->weight[u][w];
	}
}

int main(void)
{
	printf("********** �ִ� ���(Shortest Path) ���ϱ� ********** \n");
	printf("���ͽ�Ʈ�� ��� \n");
	printf("--------------------------------------\n");
	printf("********** ����ġ ���� ���(7x7) **********\n");
	printf(" 0 7 * * 3 10 *\n 7 0 4 10 2 6 *\n * 4 0 2 * * *\n * 10 2 0 11 9 4\n 3 2 * 11 0 * 5\n 10 6 * 9 * 0 *\n * * * 4 5 * 0\n");
	printf("***** ���ͽ�Ʈ�� ��� *****\n");
	GraphType g = { 7,
	{{ 0,  7,  INF, INF,   3,  10, INF },
	{ 7,  0,    4,  10,   2,   6, INF },
	{ INF,  4,    0,   2, INF, INF, INF },
	{ INF, 10,    2,   0,  11,   9,   4 },
	{ 3,  2,  INF,  11,   0, INF,   5 },
	{ 10,  6,  INF,   9, INF,   0, INF },
	{ INF, INF, INF,   4,   5, INF,   0 } }
	};
	shortest_path(&g, 0);
	return 0;
}

