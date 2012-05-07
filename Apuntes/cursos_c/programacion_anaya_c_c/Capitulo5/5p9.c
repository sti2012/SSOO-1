#include <stdio.h>

double potencia (long base, long exponente)
{
	if (exponente == 2)
		return (base * base);
	else
		return (base * potencia(base, exponente -1));
}

void main ()
{
	printf ("%lf\n", potencia (2, 3));
}
