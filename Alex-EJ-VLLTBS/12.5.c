/* Ejercicio 12.5:  (calculaMaximo.c)
   Hacer un programa que pida números al usuario hasta que éste introduzca un cero.
   En ese momento el programa debe imprimir el número mayor(valor máximo) que  
   introdujo el usuario.
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
   int numero;
   int mayor=0;
   do
   {
      printf("Introduce un numero: ");
      scanf("%d", &numero);
      if (numero > mayor) mayor = numero;
    }while(numero != 0);

   printf("El numero introducido mayor ha sido: %d\n", mayor);
   system("pause");
}