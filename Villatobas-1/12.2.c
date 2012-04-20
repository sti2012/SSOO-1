/* Ejercicio 12.2:  (parImpar.c)
   Crea un programa que pida números por consola y para cada número muestre un
   mensaje diciendo si el número es par o es impar. El programa terminará cuando
   el usuario introduzca el cero.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int numero;
   do
   {
      printf("Introduce un numero: ");
      scanf("%d", &numero);
      if (numero % 2 == 0)
      {
         printf("\nEl numero %d es: Par\n", numero);
      }
      else if (numero % 2 != 0)
      {
         printf("\nEl numero %d es: Impar\n", numero);
      }
   }while(numero != 0);
   system("pause");
}