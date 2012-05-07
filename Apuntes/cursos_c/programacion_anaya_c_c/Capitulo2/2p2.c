#include <stdio.h>

void main (void)
{
  char	ciudad [3][20];
  long	distancia [3];
  
  printf ("Introduzca ciudad y distancia: ");
  scanf ("%s %ld", ciudad [0], &distancia [0]);

  printf ("Introduzca ciudad y distancia: ");
  scanf ("%s %ld", ciudad [1], &distancia [1]);

  printf ("Introduzca ciudad y distancia: ");
  scanf ("%s %ld", ciudad [2], &distancia [2]);
} 

/* Albacete Alicante Almeria Avila Badajoz 
   246 412 607 111 403 */
