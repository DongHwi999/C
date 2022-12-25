#include <stdio.h>

typedef struct student{
	char name[30];
	int age;
}STUDENT;

void input(STUDENT s[],int size){
	int i;
	for(i=0;i<3;i++){ //3번 연속 입력 
		printf("\n-----------------------------\n");
		printf("이름 : ");scanf("%s",&s[i].name);
		printf("\n");
	printf("나이 : ");scanf("%d",&s[i].age);
	printf("\n-----------------------------\n");
	}
	
}
	
int main(void){
	STUDENT s[3];
	int menu;
	for(;;){
		printf("메뉴를 선택하시오.\n1. 입력\n2.출력 \n선택>>>>");scanf("%d",&menu);
		printf("\n"); 
		if(menu==1) input(s,3);  //STUDENT s 와 사이즈 3을 input메서드에 넣음.
		if(menu==2) {
			
			int i;
			for(i=0;i<3;i++){
				printf("\n-----------------------------\n");
				printf("이름:%s\n",s[i].name);
				printf("나이:%d\n",s[i].age);	
				printf("\n-----------------------------\n");
			}
			
		}
		if(menu==3) break;
	}
	return 0;
}