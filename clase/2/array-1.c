/*
	Hacer un programa que nos cree una array de enteros de nombre pares
	a) inicializalo con los 20 primeros numeros pares
	b) muestra el contenido
*/

#include <stdio.h>

int main()
{
	int pares[20];
	int i=2,x;
	for (x = 0; x < 20; i=i+2, x++)
	{
		pares[x] = i;
		printf("%d\n", pares[x]);
	}
	return 0;
}