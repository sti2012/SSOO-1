#include <stdio.h>

void main () 
{	
  char  cadena [] = "Alicante 412";
  char  ciudad [100];
  int   dis;
  int   num;

  /* Lectura de datos desde cadena */

  num = sscanf (cadena, "%s %d", ciudad, &dis);
  printf ("Variables leidas: %d\n", num);

  /* Escritura de los datos leidos */

  printf ("ciudad    = %s\n", ciudad);
  printf ("distancia = %d\n", dis);
}
