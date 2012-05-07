/*
 * Programa:    prog_04_06
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 4:
 *              Cálculo del complemento binario
 */
#include <stdio.h>


int main(void)
{
    /* Número en decimal */
    unsigned int n = 4325;

    /* Imprimir el número y su complemento */
    printf("Número: %d \n", n);
    printf("Complemento: %d \n", ~n);


    return (0);
}

