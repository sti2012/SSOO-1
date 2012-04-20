#include <stdio.h>

#define MINIMO 2
#define MAXIMO 100

int main()
{
	int i = MINIMO;
	int j = 2;
	printf("Los numeros primos entre %d y %d son:\n", MINIMO, MAXIMO);
	while(i <= MAXIMO)
	{
		while(i % j > 0)
		{
			j = j + 1;
		}
		if (i == j)
		{
			printf("%d\t", i);
		}
		i = i + 1;
		j = 2;
	}
	printf("\n");
	system("pause");
	return 0;
}