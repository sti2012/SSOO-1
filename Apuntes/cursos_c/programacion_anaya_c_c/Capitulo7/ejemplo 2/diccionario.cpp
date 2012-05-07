#include "diccionario.h"
#include <iostream>

using std::cout;
using std::endl;

void iniciar (DiccionarioConsecutivo * x, long n)
{
	x->elem = new Elemento [n];
	x->maximo = n;
	x->ultimo = 0;
}

void terminar (DiccionarioConsecutivo * x)
{
	delete [] x->elem;
}

void insertar (DiccionarioConsecutivo * x,
	          string clave, long valor)
{
	if (x->ultimo == x->maximo)
		throw "Diccionario lleno";
	x->elem [x->ultimo].ciudad = clave;
	x->elem [x->ultimo].distancia = valor;
	x->ultimo++;
}

long buscar (DiccionarioConsecutivo * x, string clave)
{
	long i;

	for (i=0; i<x->ultimo; i++)
		if (clave == x->elem [i].ciudad)
			return x->elem [i].distancia;

	return -1;
}

void listar (DiccionarioConsecutivo * x, long a, long b)
{
	long i;

	for (i=0; i<x->ultimo; i++)
		if (x->elem[i].distancia <=b &&
		    x->elem[i].distancia >=a)
			cout << x->elem[i].ciudad << endl;
}
