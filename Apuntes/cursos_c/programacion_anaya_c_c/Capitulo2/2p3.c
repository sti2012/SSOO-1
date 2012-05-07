#include <stdio.h>

#define MAX 20

typedef struct
{
  char  ciudad [MAX];
  long  distancia;
} Elemento;

void main (void)
{
  Elemento plano [3];
  
  printf ("Introduzca ciudad y distancia: ");
  scanf ("%s %ld", plano [0].ciudad, &plano [0].distancia);

  printf ("Introduzca ciudad y distancia: ");
  scanf ("%s %ld", plano [1].ciudad, &plano [1].distancia);

  printf ("Introduzca ciudad y distancia: ");
  scanf ("%s %ld", plano [2].ciudad, &plano [2].distancia);
} 

/* Albacete Alicante Almeria Avila Badajoz 
   246 412 607 111 403 */
