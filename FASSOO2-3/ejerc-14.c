/*
	Realiza un programa que nos muestre la diferencia entre el operador
	postincremento y preincremento.
*/

#include <stdio.h>

int main () 
{
	printf("Para el valor inicial x=10\n");
	int x=10;
	int y;
	y=x++;
	printf("\nPost-incremento (y=x++)\n");
	printf("x = %d | y = %d\n",x,y);
	x=10;
	y=++x;
	printf("\nPre-incremento (y=++x)\n");
	printf("x = %d | y = %d\n",x,y);
	printf("\n");
	system("pause");
	return 0;
}