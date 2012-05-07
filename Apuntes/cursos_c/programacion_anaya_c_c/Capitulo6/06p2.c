#include <stdio.h>

void main () {

	char cadena [100];
	printf ("Introduzca una cadena: ");
	if (gets (cadena) == NULL)
	  printf ("Error");
	else
	  printf ("La cadena leida es: %s", cadena);
}