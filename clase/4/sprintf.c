#include <stdio.h>

/*
printf(cadena);
fprintf(stdout, cadena);
sprintf(char *buffer, cons char);

*/

int main()
{
	char car[10] = "Test";
	char mensaje[100];
	//char puntero=*car;
	//char mensaje[100];
	//sprintf(stdout, &puntero);
	sprintf(mensaje, "El mensaje es %s", car);
	printf("%s\n", mensaje);
	return 0;
}