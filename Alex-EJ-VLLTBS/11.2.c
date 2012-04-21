/* Ejercicio 11.2:
    Crea un programa que, utilizando cuatro variables char, les asigne los
    valores adecuados para que al imprimirlos uno tras otro, leamos la palabra:
    "Hola"
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char h,o,l,a;

	h = 'H';
	printf("%c", h);
	o = 'o';
	printf("%c", o);
	l = 'l';
	printf("%c", l);
	a = 'a';
	printf("%c", a);

	printf("\n");
	system("pause");
	return 0;
}