#include <stdio.h>

void main () {
  FILE * p = fopen ("plano.txt", "w");
  fprintf (p, "Albacete %d\n", 246);
  fprintf (p, "Alicante %d\n", 412);
  fprintf (p, "Almeria %d\n", 607);
  fclose (p);
}