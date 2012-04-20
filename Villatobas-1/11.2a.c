/* Ejercicio 11.2:
    Crea un programa que, utilizando cuatro variables char, les asigne los
    valores adecuados para que al imprimirlos uno tras otro, leamos la palabra:
    "Hola"
*/

#include <stdio.h>
#include <stdlib.h>

/*
int palabra;
palabra = Hola;

#define HOLA Hola
*/

int main()
{
  int i;
  char hola[4] = {'H','o','l','a'};
  for (i = 0; i <= 3; i++) 
  {
    printf("%c", hola[i]);
  }
  printf("\n");
  system("pause");
}