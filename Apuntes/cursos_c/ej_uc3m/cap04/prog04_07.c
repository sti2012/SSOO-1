/*
 * Programa:    prog_04_07
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 4:
 *              Calculo de operadores l�gicos binarios
 */
#include <stdio.h>


int main(void)
{
    int a = 8;  /* 1000 */
    int b = 5;  /* 0101 */
    int c = 3;  /* 0011 */
    
    printf("AND binario de %d y %d es %d\n", a, b, a & b);
    printf("OR binario de %d y %d es %d\n", a, c, a | c);
    printf("XOR binario de %d y %d es %d\n", b, c, b ^ c);

    return (0);
}

