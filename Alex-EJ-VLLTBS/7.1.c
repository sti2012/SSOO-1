/*
	Ejercicio 7.1:
	Realizar un programa que, mediante el algoritmo de las restas sucesivas,
	calcule el cociente de la división entera de los siguientes números:
	9/3, 11/10, 7/7 5/6.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int contador=0;
	int resta;
	int dividendo;
	int divisor;
	printf("Cual es el dividendo?: ");
	scanf("%d", &dividendo);
	printf("Cual es el divisor? ");
	scanf("%d", &divisor);
	resta = dividendo;

	if (dividendo >= divisor)
	{
		do
		{
			resta = resta - divisor;
			contador = contador + 1;
		}while(resta >= divisor);
		printf("El cociente entero de %d/%d es %d\n", dividendo, divisor, contador);
		system("pause");
	}
	else
		printf("El cociente entero de %d/%d es 0\n", dividendo, divisor);
	system("pause");
	return 0;
}