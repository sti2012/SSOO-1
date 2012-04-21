/*
	Ejercicio 12.3:  (cuentaParesImpares.c)
	Modificar el programa del ejercicio 12.2 para que antes de terminar se informe
	al usuario de cuántos números pares y cuántos impares se han introducido.   
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numero;
	int cuentaPar=0;
	int cuentaImpar=0;

	do
	{
		printf("Introduce un numero: ");
		scanf("%d", &numero);
		if (numero % 2 == 0)
		{
			printf("Ese numero es: Par\n");
			cuentaPar = cuentaPar + 1;
		}
		else if (numero % 2 != 0)
		{
			printf("Ese numero es: Impar\n");
			cuentaImpar = cuentaImpar + 1;
		}
	}while(numero != 0);
	printf("Has introducido %d numeros pares y %d numeros impares\n", cuentaPar, cuentaImpar);
	system("pause");
	return 0;
}