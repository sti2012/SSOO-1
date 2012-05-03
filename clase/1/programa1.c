// Convertir Decimal en Hexadecimal y Octal.
#include <stdio.h>

int main()
{
	int numero;
	printf("Dime un numero\n");
	scanf("%d", &numero);
	printf("El numero %d equivale al %x en hexadecimal y al %o en octal.\n", numero, numero, numero);
	return 0;
}