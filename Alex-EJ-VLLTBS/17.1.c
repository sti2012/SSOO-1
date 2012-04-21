// No funciona.
// Mal hecho.

/*
	Ejercicio 17.1  (estadisticaEdad.c)
	Escribe un programa que pida al usuario 10 valores de edades.
	El programa mostrará entonces un listado con las edades introducidas y
	a continuación la edad media, la edad más alta y la más baja de todas.
*/

#include <stdio.h>

#define EDADES 10

float check(float x)
{
	float mayor, menor;
	if (x > mayor && x != 666666)
	{
		mayor = x;
		printf("test2\n");
	}
	else if (x < menor)
	{
		menor = x;
		printf("test1\n");
	}
	else if ((x > 666666 && x > 125) || x < 1 )
	{
		printf("Introduce una edad coherente, no existe nadie menor que 0 o mayor que 125\n");
	}
	else if (x == 666666)
	{
		printf("La edad mas alta es: %.1f\n", mayor);
		printf("La edad mas baja es: %.1f\n", menor);
	}
}

int main()
{
	float edades[EDADES];
	float media, total;
	int i;

	printf("Escribe 10 valores de edades: \n");
	printf("  1.\t___\b\b\b");
	scanf("%f", &edades[0]);
	printf("  2.\t___\b\b\b");
	scanf("%f", &edades[1]);
	printf("  3.\t___\b\b\b");
	scanf("%f", &edades[2]);
	printf("  4.\t___\b\b\b");
	scanf("%f", &edades[3]);
	printf("  5.\t___\b\b\b");
	scanf("%f", &edades[4]);
	printf("  6.\t___\b\b\b");
	scanf("%f", &edades[5]);
	printf("  7.\t___\b\b\b");
	scanf("%f", &edades[6]);
	printf("  8.\t___\b\b\b");
	scanf("%f", &edades[7]);
	printf("  9.\t___\b\b\b");
	scanf("%f", &edades[8]);
	printf(" 10.\t___\b\b\b");
	scanf("%f", &edades[9]);

	/*
		for (i=0; i < EDADES; i++)
		{
			check(edades[i]);
		}
	*/

	total = 0; 

	for (i=0; i < EDADES; i++)
	{
		total = total + edades[i];
		check(edades[i]);
	}
	media = total / EDADES;

	printf("La edad media es: %.1f\n", media);

	check(666666); // Mala forma de hacerlo

	system("pause");
	return 0;
}