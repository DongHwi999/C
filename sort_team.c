#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand((unsigned)time(NULL));
    
    int athlete = 0;
    int trade = 0;
    int SumBefore = 0;
    int SumAfter = 0;
    double AverageBefore = 0;
    double AverageAfter = 0;
    
    //Enter amount of athlete, trade num
    scanf("%d %d", &athlete, &trade);
    
    int HomeTeam[athlete];
    int AwayTeam[athlete];
    int RandomNum[trade];
    
    // Enter Team Score
    printf("�츮�� ���� ����: ");
    int i;
    for(i = 0; i < athlete; i++) {
        scanf("%d", &HomeTeam[i]);
    }
    printf("����� ���� ����: ");
    for( i = 0; i < athlete; i++) {
        scanf("%d", &AwayTeam[i]);
    }
    
    //Average Score
    for(i = 0; i < athlete; i++) {
        SumBefore += HomeTeam[i];
    }
    AverageBefore = (double)SumBefore / athlete;
    
    //Random Num
    for(i = 0; i < trade; i++) {
        RandomNum[i] = rand() % athlete;
        int j;
        for(j = 0; j < i; j++) {
            if(RandomNum[i] == RandomNum[j]) {
                i--;
            }
        }
    }
    
    //Trade
    for(i = 0; i < trade; i++) {
        HomeTeam[RandomNum[i]] = AwayTeam[RandomNum[i]];
    }
    
    //Average Score after trade
    for(i = 0; i < athlete; i++) {
        SumAfter += HomeTeam[i];
    }
    AverageAfter = (double)SumAfter / athlete;
    
    printf("��ȯ�� ���� : ");
    for(i = 0; i < athlete; i++) {
        printf("%d ", HomeTeam[i]);
    }
    printf("\n");
    printf("���� ��� ��ȭ : %.1f -> %.1f \n", AverageBefore, AverageAfter);
}

