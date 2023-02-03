#include <ctype.h>
#include <stdio.h>
int main()
{
	char ch = ' ';
	
	if(isspace(ch))
		printf("\nEntered character is space");
	else
		printf("\nEntered character is not space");
}
