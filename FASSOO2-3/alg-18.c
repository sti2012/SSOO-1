#include <stdio.h>

int main ()
{
    int suma = 1;
    int contador = 2;
    int numero = 0;
    printf("Suma de numeros naturales.\n");
    printf("Introduce el valor maximo: ");
    scanf("%d", &numero);
    while(contador <=numero)
	{
	   suma = suma + contador;
	   contador++;
	}
    printf("La suma de los numeros del 1 al %d es %d\n", numero, suma);
    system("pause");
    return 0;
}