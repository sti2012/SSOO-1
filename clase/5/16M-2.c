/* Realiza un programa que nos genere 6 numeros aleatorios */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 6; ++i)
	{
		int num = rand()%100;
		printf("%d\t", num);
	}
	return 0;
}