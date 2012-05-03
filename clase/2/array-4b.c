/*
	Ejercicio que nos pida una cadena de caracteres y no las muestre caracter
	a caracter separados por una tabulacion
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char saludo[20];
	char *psaludo=saludo;
	printf("Escribe una frase\n");
	scanf("%[^\n]s", saludo); // !!! importante !!!
	while(*psaludo != '\0') // !!! Comilla simple !!!
	{
		printf("%c\t", *psaludo);
		psaludo++;	
	}
	return 0;				
}