/* Ejercio 8.1. gauss.c:
      Realizar un programa que calcule, mediante la f�rmula de Gauss, el sumatorio de los n�meros
      del 1 al 100.
*/   

#include <stdio.h>
#include <stdlib.h>

/*Suma de los primeros 100 n�meros naturales: S100
De acuerdo a la f�rmula de Gauss:

Sn = (a1+an)n / 2 =>

S100 = (1+100)100 / 2 =>
S100 = (101)100 / 2 =>
S100 = 10100 / 2 =>
S100 = 5050
*/

int main()
{
    int INICIO=1;
    int FIN=100;
    int SUMATORIO;
    SUMATORIO = ((INICIO+FIN)*FIN)/2;

    printf("El sumatorio de %d es %d \n", FIN, SUMATORIO);
    system("pause");
}