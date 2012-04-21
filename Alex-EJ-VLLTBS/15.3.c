/* Ejercicio 15.3.  (potencias.c)
      Supongamos que no contamos con la función pow(). Para un determinado
      proyecto nos encargan diseñar y codificar una función similar, pero de
      nombre "potencia", que solo trabaje con valores enteros positivos.
      Si la función recibe algún valor de parámetro erróneo, devolverá el
      valor -1.
      Escribe cómo sería el prototipo de la función y codifica dicha función.
      Realiza pruebas para los valores de la base y el exponente siguientes:
       2 y 2, 3 y 0, 8 y 2, 9 y 7
*/

#include <math.h>
#include <stdio.h>

potencia(int a, int b)
{
   int i;
   int m = a;
   int exp = b;
   
   if (a > 0 && b > 0)
   {
      for (i = 1; i < exp; ++i)
      {
         m = m * m;
      }
      return m;
   }
   else 
   {
      return -1;
   }
}

int main()
{
   int base, exponente;
   int resultado;

   printf("Introduce la base: ");
   scanf("%d", &base);
   printf("Introduce el exponente: ");
   scanf("%d", &exponente);
   
   resultado = potencia(base, exponente);

   printf("El resultado es: %d \n", resultado);

   system("pause");
}