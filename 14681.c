#include <stdio.h>

int main(void) 
{
	int x, y, Quad1or2, Quad3or4, Quad;

	scanf_s("%d\n%d", &x, &y);

	Quad = y>0? (Quad1or2 = (x > 0 && x <= 1000 && y <= 1000) ? 1 : 2):
	(Quad3or4 = (x<0 && x >= -1000 && y >= -1000) ? 3 : 4);

	printf("%d\n", Quad);

}
