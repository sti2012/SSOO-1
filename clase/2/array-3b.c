/*
	Hacer un programa que nos lea 5 numeros naturales de un vector. 
	A continuacion que nos lo ordene de mayor a menor. 
	Para ordenarlos utilizaremos un sgundo array donde el primer array copiara el mayor numero (y lo borrara del primer array poniendo la posicion donde estaba el mayor a 0).
	A continuacion el siguiente asi hasta 5 veces.
*/

#include <stdio.h>

int main()
{
	unsigned int vector[5], otrovector[5];
	int i,j,k,valor,max;
	for (i = 0; i < 5; i++)
	{
		printf("Introduce el numero natural %d:",i);
		scanf("%u", &vector[i]);
	}
	for (j = 0; j < 5; j++)
	{
		max=vector[0];
		valor=0;
		for (k = 0; k < 5; k++)
		{
			if (vector[k]>max)
			{
				max=vector[k];
				valor=k;
			}
			otrovector[j]=max;
			vector[valor]=0;
		}
		printf("El elemento ordenado %d es %u\n",j,otrovector[j] );
	}
	return 0;
}