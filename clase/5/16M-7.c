/* Realizar un programa en C que muestre los caracteres cirilicos (Codigos Unicode \0400 al \04FF) */

#include <stdio.h>
#define INICIO '\u0400'
#define FIN '\u04FF'

int main()
{
	int inicio = INICIO;
	int fin = FIN;
	for (; inicio < fin; ++inicio)
	{
		printf("%c\n", inicio);

	}

	/*
	int ini = INICIO +1;
	int fin;
	printf("%d\n", ini);
	sprintf(ini, "%x", INICIO);
	sprintf(fin, "%x", FIN);
	printf("%c\n", ini);
	printf("%d\n", '\u04FF');
	*/

	return 0;
}