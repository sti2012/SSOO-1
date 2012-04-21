/*
	Escribe en la pantalla del ordenador mediante un programa en lenguaje C
	y utilizando un #define MENSAJE “No faltaré sin causa justificada a clase”.
*/

#include <stdio.h>

#define MENSAJE "No faltare sin causa justificada a clase"

int main()
{
	printf(MENSAJE"\n");
	system("pause");
	return 0;
}