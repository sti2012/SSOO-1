/*
 * Programa:    prog_10_06
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 10:
 *              Programa que muestra un ejemplo de unión
 */

#include <stdio.h>

union Datos {
    int entero;
    double real;
};

int main(void)
{
    union  Datos dato;

    printf("El tamaño de un int es %d\n", sizeof(int));
    printf("El tamaño de un double es %d\n", sizeof(double));
    printf("El tamaño de la unión es %d\n", sizeof(union Datos));

    dato.entero = 8;
    printf("El valor entero de la unión es %d\n", dato.entero);
				    
    dato.real = 8.24;
    printf("El valor real de la unión es %f\n", dato.real);

    return(0);
}

