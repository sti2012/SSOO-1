/*
	Ejercicio 12.6:  (detectaVocal.c)
	Codificar un programa que lea caracteres por teclado hasta que el usuario
	introduzca una vocal. Nota: el operador OR en C es "||". Ejemplo:
	if (a > b || a == 0)  -> si a es mayor que b, o a es igual a cero, entonces...
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c;
	printf("Introduce caracteres: ");
	do
	{
		scanf("%c", &c);
	}while(!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'));
	// }while(c != 'a' || c != 'e' || c != 'i' || c != 'o' || c != 'u');
	system("pause");
	return 0;
}