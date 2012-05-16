/* Realiza un programa que le pasemos un valor y nos calcula el factorial de dicho numero */

#include <stdio.h>
#include <stdlib.h>

int factorial(int x)
{
	int m=x;
	int n=x;
	for(; m > 1; m--)
	{
		n = n*(m-1);
	}
	return n;
}

int main()
{
	int resultado;
	int factornum;
	printf("Escribe el numero que deseas factorizar: ");
	scanf("%d", &factornum);
	resultado = factorial(factornum);
	printf("%d! = %d\n", factornum, resultado);
	return 0;
}