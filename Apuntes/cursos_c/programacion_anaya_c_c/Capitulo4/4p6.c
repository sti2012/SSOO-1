#include <stdio.h>

#define MAX 20

typedef struct
{
	char  ciudad [MAX];
	long  distancia;
} Elemento;

void main (void)
{
	Elemento plano;
	Elemento * p = &plano;

	printf ("Introduzca ciudad: ");
	scanf ("%s", plano.ciudad);

	printf ("Introduzca ciudad: ");
	scanf ("%s", &p->ciudad);
}
