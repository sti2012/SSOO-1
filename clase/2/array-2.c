/*
	Hacer un programa que nos cree un array de enteros de nombre numeros de 10 elementos
	a) inicializa el array con numeros positivos, negativos y cero
	b) contabiliza el numero de numeros positivos, negativos y ceros
	c) muestra los resultados
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
	//	int numeros[10]={2,5,3,0,-5,7,-2,0,-8,-10};
	int numeros[10];
	int pos=0,neg=0,cero=0;
	printf("Escribe 10 numeros:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d. ___\b\b\b", i+1);
		int x = i; /////// si no ponemos esto, no nos muestra el resultado de numeros que hay
		scanf("%d", &numeros[x]);
		// int x;
		// x = numeros[i];
		if (numeros[x] > 0)
		{
			pos = pos + 1;
		}
		else if (numeros[x] < 0)
		{
			neg = neg + 1;
		}
		else if (numeros[x] == 0)
		{
			cero = cero + 1;
		}
		else printf("Error!\n");
	}
	printf("Hay %d positivos, %d negativos y %d ceros\n", pos,neg,cero);
	return 0;
}