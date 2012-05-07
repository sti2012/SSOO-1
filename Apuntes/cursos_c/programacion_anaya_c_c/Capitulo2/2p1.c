#include <stdio.h>

void main ()
{
	char uno, dos, tres, cuatro;
	char cinco;

	uno = 72;
	dos = 79;
	tres = dos - 3; /* 76 es el ASCII de la L */
	cuatro = 65;
	cinco = 10;

	printf ("%c%c%c%c%c", uno, dos, tres, cuatro, cinco);
}