#include <iostream>
#include <string>

using std::cin;
using std::string;

typedef struct {
	string ciudad;
	long   distancia;
} Elemento;

typedef struct {
	Elemento elem [3];
	long     maximo;
	long     ultimo;
} DiccionarioConsecutivo;

void main (void)
{
	DiccionarioConsecutivo  plano;
 
	/* Inicializacion de plano */
	plano.maximo = 3;
	plano.ultimo = 0;

	/* Insercion de ciudades */
	for (long i=0; i<plano.maximo; i++)
	{
		printf ("Introduzca ciudad y distancia: ");
		cin >> plano.elem [0].ciudad;
		cin >> plano.elem [0].distancia;
		plano.ultimo++;
	}
}

// Albacete Alicante Almeria Avila Badajoz 
// 246 412 607 111 403 
