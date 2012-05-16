/* Realiza un programa que nos pida los valores de un array de enteros y luego nos lo ordene de menor a mayor, por el metodo de la burbuja */

#include <stdio.h>
#include <string.h>

int main()
{
	int valor[100];
	int a,b,t;
	int contador;
	printf("¿Cuantos numeros?: ");   
	scanf("%d", &contador);

	printf("\nIntroduce los numeros:\n");

	for(a = 0; a < contador ; a++)
		scanf("%d", &valor[a]);

	for(a = 1; a < contador; a++) 
	{
		for(b = contador-1; b >= a; b--) 
		{
			if(valor[b-1] > valor[b])   
			{
				t = valor[b-1];
				valor[b-1] = valor[b];
				valor[b] = t;
			}
		}
	}
	for(t = 0; t < contador; t++)
		printf("%d ", valor[t]);

	return 0;
}