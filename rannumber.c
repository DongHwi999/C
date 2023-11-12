#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL)); // 무작위 숫자를 생성하기 위한 시드 설정
    int targetNumber = rand() % 100 + 1; // 1부터 100 사이의 숫자 생성
    int guess, attempts = 0;
    printf("1부터 100 사이의 숫자를 맞추는 게임을 시작합니다.\n");
    while (attempts < 10) {
        printf("추측한 숫자를 입력하세요: ");
        scanf("%d", &guess);
        if (guess < 1 || guess > 100) {
            printf("1부터 100 사이의 숫자를 입력하세요.\n");
            continue;}

        attempts++;
        if (guess == targetNumber) {
            printf("축하합니다! 숫자 %d을(를) %d번만에 맞추셨습니다.\n", targetNumber, attempts);
            break;
        } else if (guess < targetNumber) {
            printf("제시한 숫자보다 큽니다. 남은 시도 횟수: %d\n", 10 - attempts);
        } else {
            printf("제시한 숫자보다 작습니다. 남은 시도 횟수: %d\n", 10 - attempts);}
    } if (attempts >= 10) {
        printf("10번 시도 후에도 숫자를 맞추지 못했습니다. 게임 오버! 정답은 %d입니다.\n", targetNumber);}
    return 0;}
