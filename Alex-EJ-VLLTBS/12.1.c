/*
	Ejercicio 12.1:  (cuentaNumeros.c)
	Haz un programa que pida que el usuario introduzca n�meros hasta que �ste
	introduzca el n�mero 0. Cuando introduzca cero, el programa mostrar� cu�ntos
	n�meros se han introducido, sin contar el cero, y terminar�.
*/
    
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numero;
	int contador;

	contador = 0;
	printf("Introduce numeros. '0' para terminar:\n");
	do
	{
		scanf("\n%d", &numero);
		contador = contador + 1;
	}
	while(numero != 0);
	contador = contador - 1;
	printf("\nNumeros introducidos (sin contar '0'): %d \n", contador);

	system("pause");
	return 0;
}