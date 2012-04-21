/*
	Ejercicio 9.2.:
	Realizar un programa que escriba los números del 1 al 30 separados por
	tabuladores a cinco columnas (tras imprimir 5 elementos, se insertará
	salto de línea):
	1     2     3      4     5
	6     7     8      9     10
	11    12    13     14    15
	...
	Nota: pensar una forma eficiente de saber si hay que insertar salto de línea.
*/

#include <stdio.h>
#include <stdlib.h>

#define COLUMNAS 5
#define INICIO 1
#define FINAL 30

int main()
{
	int m;
	int n=0;

	for (m = INICIO; m <= FINAL; m++, n++)
	{
		if (n % COLUMNAS == 0)
		{
			printf("\n");
			printf("%d\t", m);
		}
		else
			printf("%d\t", m);
	}

	system("pause");
	return 0;
}