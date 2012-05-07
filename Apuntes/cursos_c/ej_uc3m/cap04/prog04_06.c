/*
 * Programa:    prog_04_06
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 4:
 *              C�lculo del complemento binario
 */
#include <stdio.h>


int main(void)
{
    /* N�mero en decimal */
    unsigned int n = 4325;

    /* Imprimir el n�mero y su complemento */
    printf("N�mero: %d \n", n);
    printf("Complemento: %d \n", ~n);


    return (0);
}

