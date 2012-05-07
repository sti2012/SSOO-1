#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

/* Declaracion del tipo  */
typedef struct {
	char       ciudad [MAX];
	long       distancia;
} Elemento;

typedef struct {
	Elemento * elem;
	long       maximo;
	long       ultimo;
} DiccionarioConsecutivo;

int main (void)
{
	long   i;
	DiccionarioConsecutivo  plano;

	/* Inicializacion de plano  */
	printf ("Introduzca numero de ciudades: ");
	scanf ("%ld", &plano.maximo);
	plano.ultimo = 0;

	/* Reserva de memoria */
	plano.elem=(Elemento *) 
		malloc (plano.maximo * sizeof(Elemento));
	if (!plano.elem)
	{
		printf ("Memoria agotada\n");
		return 1;
	}

	/* Insercion de ciudades en la tabla */
	for (i=0; i<plano.maximo; i++) 
	{
		printf ("Introduzca ciudad y distancia: ");
		scanf ("%s", plano.elem [i].ciudad);
		scanf ("%ld", &plano.elem[i].distancia);
		plano.ultimo++;
	}

	/* Liberacion de memoria */
	free (plano.elem);

	return 0;
}