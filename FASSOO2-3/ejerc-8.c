/*
	Escribe en la pantalla del ordenador mediante un programa en lenguaje C
	y utilizando el bucle for “No faltaré sin causa justificada a clase”.
*/

#include <stdio.h>

int main()
{
	int i=0;
	for(;;)
	{
		printf("%d - No faltare sin causa justificada a clase\n", i);
		i++;
	}
	system("pause");
	return 0;
}