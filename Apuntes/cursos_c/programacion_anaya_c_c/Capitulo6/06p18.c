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
} DiccionarioConsecutivo; 

void iniciar (DiccionarioConsecutivo * x, long n)
{
  x->elem = (Elemento *) 
    malloc (n * sizeof (Elemento));
  x->maximo = n;
  x->ultimo = 0;
}

void terminar (DiccionarioConsecutivo * x)
{
  free (x->elem);
}

int insertar (DiccionarioConsecutivo * x, char * clave, long valor)
{
  if (x->ultimo == x->maximo) 
    return 1;
  strcpy (x->elem [x->ultimo].ciudad, clave);
  x->elem [x->ultimo].distancia = valor;
  x->ultimo++;

  return 0;
}

void escribir (DiccionarioConsecutivo * x, char * nombre)
{
  long i;
  long longitud;

  FILE * p = fopen (nombre, "wb");
  fwrite (&(x->maximo), sizeof (long), 1, p);
  for (i=0; i<x->maximo; i++) 
  {
    longitud = strlen (x->elem[i].ciudad);
    fwrite (&longitud, sizeof (long), 1, p);
    fwrite (x->elem[i].ciudad, sizeof (char), longitud, p);
    fwrite (&(x->elem[i].distancia), sizeof (long), 1, p);
  }
  fclose (p);
}

void main () {
  DiccionarioConsecutivo	plano;
	
  iniciar  (&plano, 3);
  insertar (&plano, "Albacete", 246);
  insertar (&plano, "Alicante", 412);
  insertar (&plano, "Almeria", 607);
  escribir (&plano, "plano.bin");
  terminar (&plano);
}