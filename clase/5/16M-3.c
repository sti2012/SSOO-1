/* Realiza un programa que nos pida los valores de un array de enteros y luego nos lo ordene de menor a mayor, por el metodo de la burbuja */

#include <stdio.h>
#define NUM 4

int main()
{
	int array[NUM];
	int temp;
	int x;
	printf("Dime 5 numeros\n");
	for (int x = 0; x <= NUM; x++)
	{
		scanf("%d", &array[x]);
	}
	for (int i = 1; i < NUM; ++i)
	{
		for (int j = 0; j < NUM-i; ++j)
		{
			if (array[j] > array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	for (int x = 0; x <=4; x++)
	{
		printf("%d ", array[x]);
	}



	return 0;
}