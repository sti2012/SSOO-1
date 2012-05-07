#include "diccionario.h"
#include <stdio.h>

int main ()
{
	DiccionarioConsecutivo  plano;
	FILE                    * f;
	Elemento                aux;

	if (!(f = fopen ("plano.txt", "r")))
	{
		printf ("Error de apertura\n");
		return 1;
	}

	if (iniciar (&plano, 46) == 1)
	{
		printf ("Memoria agotada\n");
		return 2;
	}

	while (!feof (f))
	{
		fscanf (f, "%s %d", aux.ciudad, &aux.distancia);

		if (insertar (&plano, aux.ciudad, aux.distancia) == 1)
		{
			printf ("Diccionario lleno\n");
			return 3;
		}
	}

	fclose (f);

	listar (&plano, 200, 300);
	terminar (&plano);

	return 0;
}