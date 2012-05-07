/*
 * Programa:    prog_03_03
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 3:
 *              Programa de ejemplo que usa punteros.
 */

#include <stdio.h>

int main(void)
{
    int x;     /* variable de tipo entero */
    int y;     /* variable de tipo entero */
    int *px;   /* variable de tipo puntero a entero */


    x = 5;     /* asigna a x el valor 5 */
    px = &x;   /* asigna a px la direcci�n de x */
    y = *px;   /* asigna a y el contenido de la direccion 
		  almacenada en px */

    printf("x esta en la direcci�n %p y su valor es %d \n", &x, x);
    printf("y esta en la direcci�n %p y su valor es %d \n", &y, y);
    printf("px esta en la direcci�n %p y su valor es %p \n", &px, px);
    printf("El valor de *px es %d\n", *px);

    return(0);
}

