/* Ejercicios:
    14.1. (factorial.c)
    codifica una función que calcule el factorial del
    número pasado como parámetro. Diseña el prototipo de la
    función de acuerdo a la naturaleza de dicho parámetro y
    a la del resultado. Usa la función factorial en el programa
    principal para distintos valores.
*/

#include <stdio.h>
#include <stdlib.h>

int factorial(int x)
{
      int m=x;
      int n=x;
      for (m; m > 1; m--)
      {
        n = n*(m-1);
      }
//      printf("%d! = %d\n", x, n);
      return n;
}

int main()
{
  int resultado;
  int factornum;
  printf("Escribe el numero que deseas factorizar: ");
  scanf("%d", &factornum);
  resultado = factorial(factornum);
  printf("El factorial de %d es %d\n", factornum, resultado);
  system("pause");
}