/*
	Ejercicio 15.2.  (trigonometria.c)
	Las funciones para calcular el seno y coseno de un ángulo son las
	siguientes:
		double sin(double arg);
		double cos(double arg);
		el parámetro arg debe estar en radianes.
	Hacer un programa que pregunte al usuario el valor de un ángulo en grados,
	y muestre por pantalla el valor de su seno y de su coseno.
*/

#include <math.h>
#include <stdio.h>

#define PI 3.14159

int main()
{
	float ang, arg;
	float seno, coseno;
	printf("Escribe un angulo en grados: ");
	scanf("%f", &ang);
	arg = (ang*PI)/360;
	seno = sin(arg);
	coseno = cos(arg);
	printf("Su coseno es %.1f\nSu seno es %.1f\n", seno, coseno);
	system("pause");
	return 0;
}