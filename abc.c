#include <signal.h>

#include <stdlib.h>

#include <stdio.h>

void MySigHandler(int signo);

void Test();

int main(void)

{   

     _set_abort_behavior( 0, _WRITE_ABORT_MSG);//abort 함수 호출하였을 때 오류 창 뜨지 않게 설정

    signal(SIGABRT,MySigHandler);//SIGABRT 시그널 핸들러 등록   

    Test();//테스트

    return 0;

}

 

void MySigHandler(int signo)

{

    printf("%d signal 발생\n",signo);

    if(signo == SIGABRT)//발생한 시그널이 SIGABRT일 때

    {

        signal(SIGABRT,SIG_DFL);//SIGABRT 시그널 핸들러를 디폴트로 설정

    }

}

void Test()

{

    printf("Test 1\n");//테스트 용

    abort();//SIGABRT 발생 raise(SIGABRT); 와 같음

    printf("Test 2\n");//테스트 용

    abort();//SIGABRT 발생 raise(SIGABRT); 와 같음

    printf("Test 2\n");//테스트 용

}