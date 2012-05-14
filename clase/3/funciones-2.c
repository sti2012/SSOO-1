#include <stdio.h>

float suma(float x, float y)
{
	float resultado = x + y;
	return resultado;
}

int main(float argc, char const *argv[])
{
	float x,y;
	printf("Dime dos numeros:\n");
	scanf("%f %f", &x, &y);
	printf("%.2f + %.2f = %.2f\n", x, y, suma(x,y));
	return 0;
}