#include "diccionario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int iniciar (DiccionarioConsecutivo * x, long n)
{
  x->elem = (Elemento *) malloc (n * sizeof (Elemento));
  if (!x->elem)
    return 1;
  x->maximo = n;
  x->ultimo = 0;
  return 0;
}

void terminar (DiccionarioConsecutivo * x)
{
  free (x->elem);
}

int insertar (DiccionarioConsecutivo * x, 
              char * clave, long valor)
{
  if (x->ultimo == x->maximo) 
    return 1;
  strcpy (x->elem [x->ultimo].ciudad, clave);
  x->elem [x->ultimo].distancia = valor;
  x->ultimo++;
  return 0;
}

long buscar (DiccionarioConsecutivo * x, char * clave)
{
  long i;
	
  for (i=0; i<x->ultimo; i++)
    if (strcmp (clave, x->elem [i].ciudad) == 0)
      return x->elem [i].distancia;

  return -1;
}

void listar (DiccionarioConsecutivo * x, long a, long b)
{
  long i;

  for (i=0; i<x->ultimo; i++)
    if (x->elem[i].distancia <=b && 
        x->elem[i].distancia >=a)
      printf ("%s\n", x->elem[i].ciudad);
}
