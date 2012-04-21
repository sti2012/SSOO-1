/* EJERCICIO 20.4
         En el m�todo de la burbuja con recorrido de derecha a izquierda 
         se coloca el menor elemento al principio del intervalo
         recorrido. Escribe los valores intermedios obtenidos en cada iteaci�n
         para los vectores aplicando este m�todo:
         {2, 4, 9, 0, 7, 1, 3}
         {-4, 25, 8, 0, 32, 32, 14, 4}
*/

#include <stdio.h>
/*  PROGRAMA 20: ORDENACI�N DE ARRAYS UTILIZANDO EL M�TODO DE LA BURBUJA.
    Este m�todo consiste en recorrer el array (de izquierda a derecha o de
    derecha a izquierda, seg�n la variante del m�todo utilizada) comparando
    los elementos situados en posiciones adyacentes e intercambi�ndolos entre
    s� cuando est�n descolocados.

 */

#define LONGITUD 10
int main()
{
   int vector[LONGITUD]= {5,7,0,9,1,6,9,7,10,3};
   int i, j, k, aux;

   /* Este programa recorre de izquierda a derecha el array: en cada
      iteraci�n se consigue colocar el mayor elemento a la derecha

      Para externo: nos indica hasta qu� elemento vamos a recorrer.
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