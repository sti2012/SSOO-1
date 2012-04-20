#include <stdio.h>

int main()
{
	int suma = 0;
	int contador = 0;
	int i=1;
		for(; i * 3 < 100; i++)
		{
			suma = 3 * i;
			contador = contador + suma;
			printf("3*%d = %d  \t| La suma es %d\n", i, suma, contador);
		}
		printf("\nLa suma de los multiplos de 3 entre 3 y 99 es: %d\n\n", contador);

	system("pause");
	return 0;
}