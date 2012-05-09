/*
 * Programa:    prog_07_04
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 7:
 *              Programa que usa parametros por referencia
 */
#include <stdio.h>

void incrementar(int *a);

int main(void)
{
    int x = 5;

    printf("Antes de la funci�n: %d\n", x);

    incrementar(&x);

    printf("Despu�s de la funci�n: %d\n", x);

    return(0);
}

void incrementar(int *a)
{
    *a = *a + 1;

    printf("    Dentro de la funci�n: %d\n", *a);
}

