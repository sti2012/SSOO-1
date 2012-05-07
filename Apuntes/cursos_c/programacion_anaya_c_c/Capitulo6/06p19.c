#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

//	Declaracion del tipo diccionario
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

int leer (DiccionarioConsecutivo * x, char * nombre)
{
  long i;
  long longitud;
  char ciudad [MAX];
  long distancia;

  FILE * p = fopen (nombre, "rb");
  if (!p) 
    return 1;
  fread (&(x->maximo), sizeof (long), 1, p);
  iniciar (x, x->maximo);

  for (i=0; i<x->maximo; i++) 
  {
    fread (&longitud, sizeof (long), 1, p);
    fread (ciudad, sizeof (char), longitud, p);
    ciudad[longitud] = '\0';
    fread (&distancia, sizeof (long), 1, p);
    insertar (x, ciudad, distancia);
  }
  
  fclose (p);
  return 0;
}

void main () {
  DiccionarioConsecutivo plano;
  if (leer (&plano, "plano.bin") == 1)
	printf ("No se encontro el fichero\n");
}