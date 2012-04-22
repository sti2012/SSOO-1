/*
	Realiza el programa de una calculadora que nos este calculando
	operaciones aritméticas de dos números y nos pida la operación a realizar
	(incluye algún tipo de desplazamiento de bits) (0 para salir).
*/

#include <stdio.h>

int main()
{
	int operando1, operando2;
	char operador;
	printf ("Calculadora Simple.\n");
	printf ("Introduce el primer numero: ");
	scanf ("%d", &operando1);
	while (getchar() !='\n');
	printf ("Introduce el segundo numero: ");
	scanf ("%d", &operando2);
	while (getchar () !='\n');
	printf ("Introduzca el operador (+, -, *, /): ");
	scanf ("%c", &operador);
	while (getchar () !='\n');
	printf ("El resultado es: ");
	switch (operador)
	{
		case '+': printf("%d\n", operando1 + operando2); break;
		case '-': printf("%d\n", operando1 - operando2); break;
		case '*': printf("%d\n", operando1 * operando2); break;
		case '/': printf("%d\n", operando1 / operando2); break;
		default: printf ("Error - Operador incorrecto"); break;
	}
	system("pause");
	return 0;
}