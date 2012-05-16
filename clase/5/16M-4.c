/* Programa que nos lea un numero de 3 digitos y nos los sume */

#include <stdio.h>

int main()
{
	int num;
	int n1,n2,n3;
	int suma;
	printf("Dime un numero de 3 digitos\nNumero: ___\b\b\b");
	scanf("%d", &num);
	n1 = num/100%10;
	n2 = num/10%10;
	n3 = num%10;
	suma = n1+n2+n3;

	printf("La suma de %d + %d + %d = %d\n", n1,n2,n3,suma);
	return 0;
}