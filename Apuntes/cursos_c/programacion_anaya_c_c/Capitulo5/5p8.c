#include <stdio.h>

void main ()
{
	long  res;
	res = suma (1.5, 2);

	printf ("Suma = %ld\n", res);
}

long suma (long a, long b)
{
	int res = a+b;
	printf ("a = %d b = %d\n", a, b);
	return res;
}