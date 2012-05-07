/*
 * Programa:    prog_04_02
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 4:
 *              Programa que muestra asignaciones inadecuadas de tipos
 */
#include <stdio.h>

int main(void)
{
    /* 
     * variables enteras 
     */
    int      a = -250;
    int      b =  100000;
    unsigned c;
    short    d;

    /* 
     * variables reales
     */
    float    e = 9.87; 

    c = a;
    printf("a = %d ; c = %u\n", a, c);

    d = b;
    printf("b = %d ; d = %d\n", b, d);

    a = e;
    printf("e = %f ; a = %d\n", e, a);

    return (0);

}


