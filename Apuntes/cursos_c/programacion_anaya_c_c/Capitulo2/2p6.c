#include <stdio.h>

void main ()
{
	int numero;
	double valor;
	scanf ("%d", &numero);
	if (numero > 0) 
	{
		double iva = 0.16;
		valor = numero*iva;
		printf ("%f", valor);
	}
}