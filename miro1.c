#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int m[9][9] = { //maze, 미로를 나타내는 배열
             {2,2,2,2,2,2,2,2,2},//2는 미로의 벽
             {2,0,0,0,0,0,0,0,2},//0은 갈수 있는 길
             {2,0,2,0,2,2,2,0,2},
             {2,0,2,0,0,2,0,0,2},
             {2,0,2,0,2,0,2,0,2},
             {2,0,0,0,0,0,2,0,2},
             {2,2,0,2,2,0,2,2,2},
             {2,0,0,0,0,0,0,0,2},
             {2,2,2,2,2,2,2,2,2} };

int Si, Sj, Ei, Ej;//Start 출발, End 도착 지점 표시
int success, top, Path_i[100], Path_j[100];
//S : Start,출발점 E: End, 도착점, top 경로 배열 인덱스
//Path_i, Path_j : 지나간 길, 즉 행과 열을 저장함(i는 행, j는 열)



int visit(int, int);//미로 탐색하는 함수, 방문 여부
int main() {
    top = 0;//재귀적 용법, stack의 top 변수를 0으로 초기화
    success = 0;//미로 탈출 여부
    printf("===미로 탈출 경로 찾기 게임===\n");
    Si = 1, Sj = 1;//출발점 m배열의 1행 1열 위치
    Ei = 7, Ej = 7;//도착점 m배열의 7행 7열 위치
	int a;
    if (visit(Si, Sj) == 0)
        printf("미로의 출구를 찾을 수 없음\n");
    else
        printf("미로의 모든 경로를 찾았음\n");
    return 0;
}

void printPath() {
    for (int i = 0; i < top; i++)
        printf("[%d,%d]", Path_i[i], Path_j[i]);
    printf("\n");
}
int visit(int i, int j) {
    static int pathCount = 1;//찾은 경로의 수 카운트
    m[i][j] = 1;//배열에 0이 있다면 아직 가지 않은 길이란 의미
    //지나간 길에는 1을 저장해 둔다.
    Path_i[top] = i;
    Path_j[top] = j;
    top++;

    if (i == Ei && j == Ej) {//도착점에 도착했을 때
        printf("찾은 경로 %d번\n", pathCount++);
        printPath();//경로를 출력해주는 함수
        success = 1;//경로를 찾았음을 표시
    }
    ///////미로 탐색하기//////
    if (m[i][j + 1] == 0)//배열 오른쪽 이동
        visit(i, j + 1);
    if (m[i + 1][j] == 0)//배열 아래행으로 이동
        visit(i + 1, j);
    if (m[i][j - 1] == 0)//배열 왼쪽으로 이동
        visit(i, j - 1);
    if (m[i - 1][j] == 0)//배열 위로 이동
        visit(i - 1, j);
    top--; //재귀적 호출의 깊이를 표시, 재귀적 용법은 시스템 스택 사용
    m[i][j] = 0;//미로 탐색길을 다시 0으로 세팅
    //0으로 세팅하지 않으면 한번만 길을 찾고 끝남.
    return success;
}
