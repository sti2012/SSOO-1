/* Ejercicio 10.1:
     Modifica y recompila el programa 10 para que la suma se realice hasta 150.
*/

#include <stdio.h>
#include <stdlib.h>

#define LIMITE 150  /* especifica el valor superior de la serie de enteros */

int main()
{
      int i;
      int suma;
      suma = 0;
      for (i = 1; i <= LIMITE; i++)
         suma = suma + i;

      printf("La suma de los primeros %d numeros es %d \n", LIMITE, suma);
      system("pause");
      return 0;
}