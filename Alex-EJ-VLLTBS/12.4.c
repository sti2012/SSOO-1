/*
	Ejercicio 12.4: (calculaMedia.c)
	Haz un programa que pida al usuario cinco números y a continuación muestre el
	valor medio.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
	{
	int num1;
	int num2;
	int num3;
	int num4;
	int num5;
	int calculaMedia;

	printf("Introduce el primer numero: ");
	scanf("%d", &num1);
	printf("Introduce el segundo numero: ");
	scanf("%d", &num2);
	printf("Introduce el tercer numero: ");
	scanf("%d", &num3);
	printf("Introduce el cuarto numero: ");
	scanf("%d", &num4);
	printf("Introduce el quinto numero: ");
	scanf("%d", &num5);

	calculaMedia = (num1 + num2 + num3 + num4 + num5)/5;
	printf("El valor medio es: %d\n", calculaMedia);
	
	system("pause");
	return 0;
}