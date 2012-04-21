/*
	Escribe en la pantalla del ordenador mediante un programa en lenguaje C
	y utilizando el bucle do ... while “No faltaré sin causa justificada a clase”.
*/

#include <stdio.h>
int main()
{
	int i=0;
	do
	{
		printf("%d - No faltare sin causa justificada a clase\n", i);
		i++;
	}while(1);
	system("pause");
	return 0;
}