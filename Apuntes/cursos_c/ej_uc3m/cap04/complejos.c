/*
 * Programa:    complejos
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 4:
 *              Programa que utiliza numeros complejos
 */
#include <stdio.h>
#include <complex.h>

void main(void)
{
	float _Complex a;
	float _Complex b;
	float _Complex c;

	a = 2 + 4*I;
	a = 5 - 8*I;

	c = a + b;
	printf("a  + b = %f + %f*I\n", creal(c), cimag(c));
	c = a - b;
	printf("a  - b =  %f + %f*I\n", creal(c), cimag(c));
	c = a * b;
	printf("a  * b =  %f + %f*I\n", creal(c), cimag(c));
	c = a / b;
	printf("a  / b =  %f + %f*I\n", creal(c), cimag(c));
}



