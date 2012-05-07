/*
 * Programa:    prog_04_03
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 4:
 *              Prioridad de los operadores aritméticos
 */
#include <stdio.h>

int main(void)
{
    int  a = 4;
    int  b = 7;
    int  c = 3;
    int  d = 9;
    int resultado;

    resultado = a + b * c;
    printf("Resultado = %d\n", resultado);

    resultado = a * b / c * d;
    printf("Resultado = %d\n", resultado);

    resultado = (a + b) * (d / c);
    printf("Resultado = %d\n", resultado);



    return (0);

}


