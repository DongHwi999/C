#include <stdio.h>
// #include <stlid.h>

typedef struct studentTag{
	char name[10];
	int age;
	double gpa;
} student; 

int main(void)
{
	student a = {"kim", 20, 4.3};
	student b = {"park", 21, 4.2};
	return 0;
}


