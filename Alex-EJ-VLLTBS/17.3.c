/* Ejercicio 17.3
    Programa que lee 15 valores enteros e imprime un listado con los números
    que son mayores que el último.
*/

#include <stdio.h>

int main()
{
   unsigned int numero[15]; 
   unsigned int otronumero[15];
   int i,j,valor,max;
   for (i=0; i<15; i++)
   {
      printf("Introduce el numero natural %d: ",i);
      scanf("%u",&numero[i]);
   }
   for (j=0; j<15; j++)
   {
      max=numero[0];
      valor=0;
      for (i=1; i<15; i++)
      if (numero[i]>max)
      {
         max=numero[i];
         valor=i;
      }
      otronumero[j]=max;
      numero[valor]=0;
   }
      for (i=0; i<15; i++)
      printf("El elemento ordenado %d es %u\n",i,otronumero[i]);
      return 0;
}