#include <stdio.h>

void main () {
  char ciudades [3][20];
  long dis [3];
  long i;
  FILE * p = fopen ("plano.txt", "r");

  for (i=0; i<3; i++)
    fscanf (p, "%s %d", ciudades[i], &dis[i]);

  fclose (p);
}