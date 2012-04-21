/* Ejercicio 16.3  (aminusculas.c)
      Codificar una función con el siguiente prototipo:
        char aminusculas(char);
      que pasa a minúsculas el carácter pasado y utilízala en el programa
      16 en lugar de la función tolower.
*/

#include <stdio.h>

char aminusculas(char x)
{
  switch(x)
  {
    case 'A': return 'a'; break;
    case 'E': return 'e'; break;
    case 'I': return 'i'; break;
    case 'O': return 'o'; break;
    case 'U': return 'u'; break;
    default: return x;
  }
}

int main()
{
   char c, caracter;
   int continuar;

   continuar = 1;
   do
   {
      printf("\n\nIntroduce un carácter (S para salir): ");
      scanf("\n%c", &c);

      caracter = aminusculas(c);

      if (c != 's' && c != 'S')
      {
         switch(caracter)
         {
            case 'a': printf("\nHas pulsado la vocal: %c\n", c);
              break;
            case 'e': printf("\nHas pulsado la vocal: %c\n", c);
              break;
            case 'i': printf("\nHas pulsado la vocal: %c\n", c);
              break;
            case 'o': printf("\nHas pulsado la vocal: %c\n", c);
              break;
            case 'u': printf("\nHas pulsado la vocal: %c\n", c);
              break;
              default: printf("\n%c NO es una vocal \n", c);
         }
      }
      else
        continuar = 0;
   }while (continuar == 1);
   system("pause");
}