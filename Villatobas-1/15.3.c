/* Ejercicio 15.3.  (potencias.c)
      Supongamos que no contamos con la funci�n pow(). Para un determinado
      proyecto nos encargan dise�ar y codificar una funci�n similar, pero de
      nombre "potencia", que solo trabaje con valores enteros positivos.
      Si la funci�n recibe alg�n valor de par�metro err�neo, devolver� el
      valor -1.
      Escribe c�mo ser�a el prototipo de la funci�n y codifica dicha funci�n.
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