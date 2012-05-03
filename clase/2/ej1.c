#include <stdio.h>
#define p printf

int main()
{
	p("Si x vale 10.\n");
	int x=10;
	int y;
	y=x++;
	p("Postincremento x++:\n");
	p("x vale %d e y vale %d\n",x,y);
	//int x=10
	x=10;
	y=++x;
	p("Preincremento ++x:\n");
	p("x vale %d e y vale %d\n",x,y);
	return 0;
}