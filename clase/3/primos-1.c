// Sin terminar. Falta funcion que comprueba que numero es primo.

/* 
	Ejercicio 14.2.  (primos.c)
	codifica una funci�n que devuelva 1 si el n�mero que se
	le pasa es primo, 0 si no lo es y -1 si el par�metro pasado
	no es v�lido (por ejemplo, los valores 0, 1 o valores negativos).
	Prueba la funci�n pas�ndole diferentes valores.
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

	else if (x > 1)
	{

//			int esPrimo(int a)
		int b=0;
		int resul=1; //Es primo
		int i=2;
		while(i<x && b==0)
		{
			if(x%i==0)
			{
				b=1;
				resul=0; //No es primo
			}
			else i++;
		}
		return resul;
	}

	else 
	{
		resul = -1;
		return resul;
	}
}

int main(int argc, char const *argv[])
{
	int resultado=2;
	int numero;
	printf("Algoritmo de numeros primos (0 para salir)\n");
	do
	{

		printf("Introduce un numero: ");
		scanf("%d", &numero);
		resultado = primo(numero);
		if (resultado == 0)
		{
			printf("El numero %d no es primo\n", numero);
		}
		else if (resultado == 1)
		{
			printf("\a###################### ###################### ######################\n\t\t\tEl numero %d es primo\n###################### ###################### ######################\a\n", numero);
		}
		else if (resultado == -1)
		{
			// printf("El numero introducido no es valido\n");
			break;
		}

	}while(1);

	return 0;
}