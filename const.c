#include <stdio.h>

// define은 전처리기이므로 main밖에 써야함 (매크로 상수)
#define PI 3.141592 
#define COL 100 
#define ROW 200 

void main()
{
    // const 상수
    // 상수는 반드시 선언과 초기화를 동시에 해야 한다.
    // 일반적으로 상수는 대문자로 만듦
    const int WIDTH = 100;
    const int HEIGHT = 150;
    
    printf("WIDTH : %d\n", WIDTH);
    printf("HEIGHT : %d\n", HEIGHT);
    printf("PI : %lf\n", PI);
    
    printf("COL : %d\n", COL);
    printf("ROW : %d\n", ROW);
}
