/*  Ejercicio 13.1: escribir un programa que escriba la siguiente serie
    de números: 0, 0.2, 0.4, 0.6... hasta llegar a 10.
*/

#include <stdio.h>
#include <stdlib.h>

/* Programa 13:
   Tipo float: maneja números reales.
 */

#define SUMA 0.2

int main()
{
   float maximo;
   maximo = 0;

   while (maximo < 10)
   {
      printf("%.1f, ", maximo);
      maximo = maximo + SUMA;
   }
   printf("\n");
   system("pause");
   return 0;
}