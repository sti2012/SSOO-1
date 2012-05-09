/*
 * Programa:    prog_07_02
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 7:
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

    printf("Después de la llamada: %d %d\n", x, y);
  
    return(0);
}

void funcion(int a, int b)
{
    a = 0;
    b = 0;

    printf("    Dentro de la función: %d %d\n", a, b);
    
    return;
}

