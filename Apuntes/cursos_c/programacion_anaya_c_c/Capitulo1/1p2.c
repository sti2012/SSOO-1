#include <stdio.h>

void main ()
{
	int    altura;
	double peso, indice;

	printf ("Indice de masa corporal\n");
	printf ("Introduzca peso (Kg.): ");
	scanf ("%lf", &peso);

	printf ("Introduzca altura (cm.): ");
	scanf ("%d", &altura);

	/*
		indice = peso partido por altura 
		en metros al cuadrado
	*/

	indice = 10000 * peso / (altura * altura);

	printf ("Indice = %.2lf\n", indice);
}