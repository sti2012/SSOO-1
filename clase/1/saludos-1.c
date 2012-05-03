//Repetir lo Escrito.
#include <stdio.h>

int main()
{
	char saludo[20];
	printf("Saludame!\n");
	gets(saludo);
	printf("Tu mensaje ha sido %s.\n", saludo);
	return 0;
}