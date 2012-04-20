/* Ejercicio 17.3
    Programa que lee 15 valores enteros e imprime un listado con los n�meros
    que son mayores que el �ltimo.
*/

/* Programa 17: matrices de una dimensi�n: arrays
  (vectores, tablas unidimensionales ) en C.

   Para trabajar con conjuntos de variables del mismo tipo, que se
   referenciar�n mediante un nombre y un �ndice.

   En este programa trabajaremos con arrays de n�meros.
*/

#include<stdio.h>

/* Declaraci�n de un array:
  tipo nombre[tama�o];
*/

int main()
{
   /* arrays de n�meros */
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