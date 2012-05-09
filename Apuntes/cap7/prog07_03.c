/*
 * Programa:    prog_07_02
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 7:
 *              Programa que utiliza parametros por valor
 */
#include <stdio.h>

void funcion(int a, int b);

int main(void)
{
    int x = 2;
    int y = 3;

    printf("Antes de la llamada: %d %d\n", x, y);

    funcion(x, y);

    printf("Despu�s de la llamada: %d %d\n", x, y);
  
    return(0);
}

void funcion(int a, int b)
{
    a = 0;
    b = 0;

    printf("    Dentro de la funci�n: %d %d\n", a, b);
    
    return;
}

