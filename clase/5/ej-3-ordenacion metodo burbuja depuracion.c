#include <stdio.h>
#include <stdlib.h>
/*   ORDENACIÓN DE ARRAYS UTILIZANDO EL MÉTODO DE LA BURBUJA.
    Este método consiste en recorrer el array (de izquierda a derecha o de
    derecha a izquierda, según la variante del método utilizada) comparando
    los elementos situados en posiciones adyacentes e intercambiándolos entre
    sí cuando estén descolocados.

 */

#define LONGITUD 10
int main()
{
   int vector[LONGITUD]= {5,7,0,9,1,6,9,7,10,3};
   int iter = 0;
   int i, j, k, aux;

   /* Este programa recorre de izquierda a derecha el array: en cada
      iteración se consigue colocar el mayor elemento a la derecha
    */

   for (k = 0; k < LONGITUD; k++)
       printf("%d  ", vector[k]);
   printf("\n");
 //system("pause");
 system("delay(5)");
   /* For externo: nos indica hasta qué elemento vamos a recorrer.
      For interno: recorre el vector desde el inicio hasta el valor del
         final marcado por el for externo. */
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
       }//getch();
       iter++;
       printf("Iteracion: %d -> ", iter);
       for (k = 0; k < LONGITUD; k++)
          printf("%d  ", vector[k]);//getch();
       printf("\n");
   }

  //system("pause");system("delay(5)"");
   return 0;
}


