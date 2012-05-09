// Sin terminar. Falta funcion que comprueba que numero es primo.

/* 
	Ejercicio 14.2.  (primos.c)
	codifica una función que devuelva 1 si el número que se
	le pasa es primo, 0 si no lo es y -1 si el parámetro pasado
	no es válido (por ejemplo, los valores 0, 1 o valores negativos).
	Prueba la función pasándole diferentes valores.
*/

#include <stdio.h>
#include <stdlib.h>

int primo(int x)
{
	int resul;

	if (x <= 1)
	{
		resul = -1;
		return resul;
	}

	/////////////////////////////////////////////////
	else if (x > 1)
	{
		do
		{

		}while(x);
	}
	/////////////////////////////////////////////////

	else 
	{
		resul = -1;
		return resul;
	}
}

int main((int argc, char const *argv[])
{
	int resultado=2;
	int numero;
	printf("Introduce un numero: ");
	scanf("%d", &numero);
	resultado = primo(numero);
	if (resultado == 0)
	{
		printf("El numero %d no es primo\n", numero);
	}
	else if (resultado == 1)
	{
		printf("\a######################\nEl numero %d es primo\n######################\a\n", numero);
	}
	else if (resultado == -1)
	{
		printf("El numero introducido no es valido\n");
	}
	return 0;
}