/*
	Escribe en la pantalla del ordenador mediante un programa en lenguaje C
	y utilizando una funcion llamada recordatorio() que nos imprima el mensaje:
	“No faltaré sin causa justificada a clase”.
*/

#include <stdio.h>

#define MENSAJE "No faltare sin causa justificada a clase"

int recordatorio()
{
	printf(MENSAJE"\n");
}

int main()
{
	recordatorio();
	system("pause");
	return 0;
}