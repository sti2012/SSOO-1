/*
 * Programa:    prog_04_07
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 4:
 *              Calculo de operadores lógicos binarios
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

