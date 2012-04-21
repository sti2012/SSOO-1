/* EJERCICIO 20.4
         En el método de la burbuja con recorrido de derecha a izquierda 
         se coloca el menor elemento al principio del intervalo
         recorrido. Escribe los valores intermedios obtenidos en cada iteación
         para los vectores aplicando este método:
         {2, 4, 9, 0, 7, 1, 3}
         {-4, 25, 8, 0, 32, 32, 14, 4}
*/

#include <stdio.h>
/*  PROGRAMA 20: ORDENACIÓN DE ARRAYS UTILIZANDO EL MÉTODO DE LA BURBUJA.
    Este método consiste en recorrer el array (de izquierda a derecha o de
    derecha a izquierda, según la variante del método utilizada) comparando
    los elementos situados en posiciones adyacentes e intercambiándolos entre
    sí cuando estén descolocados.

 */

#define LONGITUD 10
int main()
{
   int vector[LONGITUD]= {5,7,0,9,1,6,9,7,10,3};
   int i, j, k, aux;

   /* Este programa recorre de izquierda a derecha el array: en cada
      iteración se consigue colocar el mayor elemento a la derecha

      Para externo: nos indica hasta qué elemento vamos a recorrer.
      Para interno: recorre el vector desde el inicio hasta el valor del
         final marcado por el para externo.
    */

   for (i = LONGITUD-2; i >= 0; i--)
   {
       for( j = 0; j <= i; j++)
       {
          if (vector[j] > vector[j+1])
          {
             aux = vector[j];
             vector[j] = vector[j+1];
             vector[j+1] = aux;
          }
       }

   }
   for (k = 0; k < LONGITUD; k++)
     printf("%d  ", vector[k]);
   printf("\n");

   system("PAUSE");
   return 0;
}