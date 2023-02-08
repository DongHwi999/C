#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int m[9][9] = { //maze, �̷θ� ��Ÿ���� �迭
             {2,2,2,2,2,2,2,2,2},//2�� �̷��� ��
             {2,0,0,0,0,0,0,0,2},//0�� ���� �ִ� ��
             {2,0,2,0,2,2,2,0,2},
             {2,0,2,0,0,2,0,0,2},
             {2,0,2,0,2,0,2,0,2},
             {2,0,0,0,0,0,2,0,2},
             {2,2,0,2,2,0,2,2,2},
             {2,0,0,0,0,0,0,0,2},
             {2,2,2,2,2,2,2,2,2} };

int Si, Sj, Ei, Ej;//Start ���, End ���� ���� ǥ��
int success, top, Path_i[100], Path_j[100];
//S : Start,����� E: End, ������, top ��� �迭 �ε���
//Path_i, Path_j : ������ ��, �� ��� ���� ������(i�� ��, j�� ��)



int visit(int, int);//�̷� Ž���ϴ� �Լ�, �湮 ����
int main() {
    top = 0;//����� ���, stack�� top ������ 0���� �ʱ�ȭ
    success = 0;//�̷� Ż�� ����
    printf("===�̷� Ż�� ��� ã�� ����===\n");
    Si = 1, Sj = 1;//����� m�迭�� 1�� 1�� ��ġ
    Ei = 7, Ej = 7;//������ m�迭�� 7�� 7�� ��ġ
	int a;
    if (visit(Si, Sj) == 0)
        printf("�̷��� �ⱸ�� ã�� �� ����\n");
    else
        printf("�̷��� ��� ��θ� ã����\n");
    return 0;
}

void printPath() {
    for (int i = 0; i < top; i++)
        printf("[%d,%d]", Path_i[i], Path_j[i]);
    printf("\n");
}
int visit(int i, int j) {
    static int pathCount = 1;//ã�� ����� �� ī��Ʈ
    m[i][j] = 1;//�迭�� 0�� �ִٸ� ���� ���� ���� ���̶� �ǹ�
    //������ �濡�� 1�� ������ �д�.
    Path_i[top] = i;
    Path_j[top] = j;
    top++;

    if (i == Ei && j == Ej) {//�������� �������� ��
        printf("ã�� ��� %d��\n", pathCount++);
        printPath();//��θ� ������ִ� �Լ�
        success = 1;//��θ� ã������ ǥ��
    }
    ///////�̷� Ž���ϱ�//////
    if (m[i][j + 1] == 0)//�迭 ������ �̵�
        visit(i, j + 1);
    if (m[i + 1][j] == 0)//�迭 �Ʒ������� �̵�
        visit(i + 1, j);
    if (m[i][j - 1] == 0)//�迭 �������� �̵�
        visit(i, j - 1);
    if (m[i - 1][j] == 0)//�迭 ���� �̵�
        visit(i - 1, j);
    top--; //����� ȣ���� ���̸� ǥ��, ����� ����� �ý��� ���� ���
    m[i][j] = 0;//�̷� Ž������ �ٽ� 0���� ����
    //0���� �������� ������ �ѹ��� ���� ã�� ����.
    return success;
}