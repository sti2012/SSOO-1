/*
 * Programa:    prog_03_03
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 3:
 *              Programa de ejemplo que usa punteros.
 */

#include <stdio.h>

int main(void)
{
    int x;     /* variable de tipo entero */
    int y;     /* variable de tipo entero */
    int *px;   /* variable de tipo puntero a entero */


    x = 5;     /* asigna a x el valor 5 */
    px = &x;   /* asigna a px la dirección de x */
    y = *px;   /* asigna a y el contenido de la direccion 
		  almacenada en px */

    printf("x esta en la dirección %p y su valor es %d \n", &x, x);
    printf("y esta en la dirección %p y su valor es %d \n", &y, y);
    printf("px esta en la dirección %p y su valor es %p \n", &px, px);
    printf("El valor de *px es %d\n", *px);

    return(0);
}

