/*
 * Programa:    prog_04_02
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 4:
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


