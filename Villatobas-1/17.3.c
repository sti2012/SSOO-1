/* Ejercicio 17.3
    Programa que lee 15 valores enteros e imprime un listado con los números
    que son mayores que el último.
*/

/* Programa 17: matrices de una dimensión: arrays
  (vectores, tablas unidimensionales ) en C.

   Para trabajar con conjuntos de variables del mismo tipo, que se
   referenciarán mediante un nombre y un índice.

   En este programa trabajaremos con arrays de números.
*/

#include<stdio.h>

/* Declaración de un array:
  tipo nombre[tamaño];
*/

int main()
{
   /* arrays de números */
   float notas[5];
   float media, total;
   int i;

   /* asignamos valores */
   notas[0] = 5.5;
   notas[1] = 3;
   notas[2] = 7;
   notas[3] = 9.5;
   notas[4] = 6;


   total = 0; /* inicializamos acumulador */
   /* calculamos la nota media */
   for (i=0; i < 5; i++)
   {
     total = total + notas[i];
   }
   media = total / 5;

   printf("La nota media es: %f \n", media);

   system("pause");
}