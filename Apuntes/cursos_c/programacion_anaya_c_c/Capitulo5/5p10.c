#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct {
	char	ciudad [MAX];
	long	distancia;
} Elemento;

typedef struct {
	Elemento  * elem;
	long      maximo;
	long      ultimo;
	void      (* iniciar) ();
} DiccionarioConsecutivo; 

void iniciar (DiccionarioConsecutivo * x, long n)
{
	x->elem = (Elemento *) 
		malloc (n * sizeof (Elemento));
	x->maximo = n;
	x->ultimo = 0;
}

void main ()
{
	DiccionarioConsecutivo plano;
	plano.iniciar = iniciar;

	plano.iniciar (&plano, 3);
}
