// No compila (?)

/* EJERCICIO 26.2  (escribeNumeros.c)
   Escribe dos funciones recursivas que escriban n números: una de 1 a n, y otra
   de n a 1, separados por espacios.
*/

#include <stdio.h>

void cuentaa(int x)
{
  for (i = 1; x > i; i++)
  {
    printf("%d ", i);
  }
  return 0;
}

void cuentab(int x)
{
  for (i = x; i > 1; i--)
  {
    printf("%d ", i);
  }
  return 0;
}

int main()
{
   int numero;
   void resultado;
   printf("Escribe un numero: ");
   scanf("%d", &numero);
   resultado = cuentaa(numero);
   resultado = cuentab(numero);

   system("pause");
   return 0;
}