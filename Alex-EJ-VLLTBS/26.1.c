/* EJERCICIO 26.1  (imprimeLinea.c)
   Modifica la función imprimeLinea para que imprima los números de línea de
   menor a mayor.
*/

#include <stdio.h>
#include <ctype.h>

void imprimeLinea(int linea);
int factorial(int n);

void imprimeLinea(linea)
{
  int x=1;
  do
  {
   printf("* %d\n", x);
   x++;
  }while(x <= linea);
}

int factorial(int num)
{
    if (num <=1)
       return 1;
    else
       return num*factorial(num - 1);
}

int main()
{
   int resultado, numero;
   imprimeLinea(5);
   
   numero = 0;
   resultado=factorial(numero);
   printf("El factorial de %d es %d \n", numero, resultado);
   
   numero = 3;
   resultado=factorial(numero);
   printf("El factorial de %d es %d \n", numero, resultado);
   
   numero = 5;
   resultado=factorial(numero);
   printf("El factorial de %d es %d \n", numero, resultado);
   
   system("pause");
   return 0;
}