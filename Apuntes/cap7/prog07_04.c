/*
 * Programa:    prog_07_04
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 7:
 *              Programa que usa parametros por referencia
 */
#include <stdio.h>

void incrementar(int *a);

int main(void)
{
    int x = 5;

    printf("Antes de la función: %d\n", x);

    incrementar(&x);

    printf("Después de la función: %d\n", x);

    return(0);
}

void incrementar(int *a)
{
    *a = *a + 1;

    printf("    Dentro de la función: %d\n", *a);
}

