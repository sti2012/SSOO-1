//Multiplicacion de dos numeros.
#include <stdio.h>

int x,y;
int main()
{
	multiplica();
	return 0;
}

int multiplica()
{
	int x; int y; int producto;
	printf("Introduce el valor de x\n");
	scanf("%d", &x);
	printf("Introduce el valor de y\n");
	scanf("%d", &y);
	producto = x * y;
	printf("El producto vale %d\n", producto);
}