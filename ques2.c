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
    // ������ ���� ���� �л��� ���� ��� 
	//printf(list);
	printf(" APPLE, 20, \n GRAPE, 15, \n BANANA, 18, \n KIWI, 12, \n GREEN ONION, 5 \n");
    
	printf("���� �絵�� ���� ������ %s �̰� �� �絵�� %f �Դϴ�" ,s.name, s.dangdo);

    return 0;
}


