#include <stdio.h>

#define MAX_NODES 7

#define MAX_INT 99999
#define NOTDEF  -1
#define OUTOFQ  -1

// [in][out]
int graph[MAX_NODES][MAX_NODES]={
//  A, B, C, D, E, F, G out
  { 0, 7, 0, 5, 0, 0, 0},// A in
  { 7, 0, 8, 9, 7, 0, 0},// B in
  { 0, 8, 0, 0, 5, 0, 0},// C in
  { 5, 9, 0, 0,15, 6, 0},// D in
  { 0, 7, 5,15, 0, 8, 9},// E in
  { 0, 0, 0, 6, 8, 0,11},// F in
  { 0, 0, 0, 0, 9,11, 0},// G in
};

int key[MAX_NODES];  // The cost
int pred[MAX_NODES]; // The Infomation of parents
int Q[MAX_NODES];
int Qcount;

void PQinit()
{
    Qcount = 0;
}

int PQinsert(int a)
{
    Q[a] = 0;
    Qcount++;
}

int PQdelmin()
{
    int i;
    int min = MAX_INT;
    int saveindex = OUTOFQ;
    for(i=0;i<MAX_NODES;i++){
        if(Q[i]==OUTOFQ) continue;
        if(key[i] < min ){
            saveindex = i;
            min = key[i];
        }
    }
    if( saveindex == OUTOFQ ) return OUTOFQ;
    Q[saveindex]=OUTOFQ;
    Qcount--;
    return saveindex;
}

int PQisempty()
{
    if(Qcount==0) return 1;
    return 0;
}

int PQdeckey(int w, int newkey)
{
    key[w]=newkey;
}

void Prim(int start)
{
    int i,v,w;
    PQinit();
    for(i=0;i<MAX_NODES;i++){
        key[i]=MAX_INT;
        pred[i]=NOTDEF;
        PQinsert(i);
    }

    key[start]=0;
    for(;!PQisempty();){
        v = PQdelmin();
        printf("%d %c\n",v,v+'A');
        for(w=0;w<MAX_NODES;w++){
            if((graph[v][w]!=0) && (key[w]>graph[v][w])){
                PQdeckey(w, graph[v][w]);
                pred[w]=v;
            }
        }
    }
}

main()
{
    Prim(3);// D is 3
    return 0;
}
