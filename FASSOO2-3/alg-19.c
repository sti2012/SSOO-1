#include <stdio.h>
#include <math.h>

int main()
{
	int base=2;
	int potencia=0;
	int resultado;
	printf("Las potencias de 2 entre 0 y 10 son:\n");
	while(potencia <= 10)
	{
		resultado = pow(base ,potencia);
		printf("2^%d =\t%d\n", potencia ,resultado);
		potencia++;
	}
	system("pause");
	return 0;
}