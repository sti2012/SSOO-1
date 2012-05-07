#include <stdio.h>

void main () {

	char cadena [] = "Se imprime esta cadena";
	char * p;

    for (p=cadena; *p!='\0'; p++)
      putchar (*p);
}