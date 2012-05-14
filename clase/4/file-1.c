#include <stdio.h>

int main()
{
	//int fprintf(FILE *stdout, const char *format, ...); 
	int numero=1;
	fprintf(stdout, "Hola\n");
	fprintf(stdout, "El numero es... %d\n", numero);
	return 0;
}