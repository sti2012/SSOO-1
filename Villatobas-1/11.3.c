/*  Ejercicio 11.3:
    Sustituye en el programa 11 el valor 'A' por '\n' y 65 por 10. El carácter
    ASCII 10 representa el salto de línea. ¿Qué resultado obtienes por pantalla?
          El caracter es

          El caracter es
          
*/

#include <stdio.h>
#include <stdlib.h>

#define CHAR_INICIO 65
#define CHAR_FINAL  126

int main()
{
	char c;

	c = '\n';
	printf("El caracter es %c \n", c);
	c = 10;
	printf("El caracter es %c \n", c);
	system("pause");
}