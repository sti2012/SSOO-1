/*
	Ejercicio 9.1.:
	Realizar un programa que imprima los n�meros pares, del 2 al 30, uno
	en cada l�nea.
*/
	
#include <stdio.h>
#include <stdlib.h>

#define INICIO 2
#define FINAL 30

int main()
{
	int m;
	for (m = INICIO; m <= FINAL; m=m+2)
	{
		 printf("%d\n", m);
	}
	system("pause");
	return 0;
}