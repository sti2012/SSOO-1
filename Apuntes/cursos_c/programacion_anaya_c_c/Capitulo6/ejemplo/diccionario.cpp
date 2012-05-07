#include "diccionario.h"
#include <iostream>

using std::cout;
using std::endl;

int iniciar (DiccionarioConsecutivo * x, long n)
{
  x->elem = new Elemento [n];
  if (!x->elem)
    return 1;
  x->maximo = n;
  x->ultimo = 0;
  return 0;
}

void terminar (DiccionarioConsecutivo * x)
{
  delete [] x->elem;
}

int insertar (DiccionarioConsecutivo * x, string clave,       
              long valor)
{
  if (x->ultimo == x->maximo) 
    return 1;
  x->elem [x->ultimo].ciudad = clave;
  x->elem [x->ultimo].distancia = valor;
  x->ultimo++;
  return 0;
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