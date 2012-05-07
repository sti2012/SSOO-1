// ejemplo7_1.c

#include <stdio.h>

union Datos{
	int    entero;
	char   caracter;
	//double real;
};

struct Datos2{
	int    entero;
	char   caracter;
	//double real;
};

int main ()
{
	printf("Tamanio de cada miembro:\n");
	printf("---------------------\n");
	printf("sizeof(int)          = %d\n", sizeof(int));
	printf("sizeof(char)         = %d\n", sizeof(char));
	//printf("sizeof(double)       = %d\n\n", sizeof(double));
	printf("Tamanio de la estructura:\n");
	printf("---------------------\n");
	printf("sizeof(union Datos) = %d\n", sizeof(union Datos));
	printf("sizeof(struct Datos) = %d\n", sizeof(struct Datos2));
	printf("\n");
	//system("pause"); windows
	return 0;
}
