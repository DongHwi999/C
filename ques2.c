#include <stdio.h>
#include <stdlib.h>

struct fruit{
    char name[20];
    double dangdo;
};

struct fruit list[]={
    {"APPLE", 20},
    {"GRAPE", 15},
    {"BANANA", 18},
	{"KIWI", 12},
	{"GREEN ONION", 5}
	};


int main()
{
    int i;
    struct fruit s;

    int size = sizeof(list)/sizeof(struct fruit);

    s = list[0];

    for(i=1;i<size;i++){
        if(list[i].dangdo>s.dangdo){
            s =list[i];
        }
    }
    // 성적이 가장 높은 학생의 정보 출력 
	//printf(list);
	printf(" APPLE, 20, \n GRAPE, 15, \n BANANA, 18, \n KIWI, 12, \n GREEN ONION, 5 \n");
    
	printf("가장 당도가 높은 과일은 %s 이고 그 당도는 %f 입니다" ,s.name, s.dangdo);

    return 0;
}


