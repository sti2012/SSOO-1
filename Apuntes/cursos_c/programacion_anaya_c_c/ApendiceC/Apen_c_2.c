#include <stdio.h>

void main ()
{
	char          c;
	unsigned long largo;

	largo = 128;

	printf ("Introduzca un caracter: ");
	scanf ("%c", &c);

	printf ("%c = ", c);

	do 
	{
		largo /= 2;
		if (largo & c)
			printf ("1 ");
		else 
			printf ("0 ");
	} while (largo > 1);

	printf ("\n");
}
