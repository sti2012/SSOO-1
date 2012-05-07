#include <stdio.h>

void main ()
{
	long grupo [] = {1, 3, 6};
	long * p;

	printf ("Antes de que p apunte a grupo:\n");
	printf ("  p = %d o %p\n", p);

	p = grupo;
	printf ("Despues de que p apunte a grupo:\n");
	printf ("  p = %d\n", p);

	p++;
	printf ("p++ = %d\n", p);
}