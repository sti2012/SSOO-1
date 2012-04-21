/* Ejercicio 11.1:
    Haz un programa que muestre solo las letras mayúsculas de la Z a la A.
*/

#include <stdio.h>
#include <stdlib.h>

#define CHAR_INICIO 65 // 'A'
#define CHAR_FINAL  90 // 'Z'

int main()
{
      char caracter;

      for (caracter = CHAR_FINAL; caracter >= CHAR_INICIO; caracter--)
            printf("%c", caracter);

      printf("\n");
      system("pause");
      return 0;
}