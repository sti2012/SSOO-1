/*                                                                               * Programa:    prog_01_02
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 1:
 *              Búsqueda rápida de un número.
 */


#include <stdio.h>
 
int main (int argc, char **argv)
{
    int i = 0;
    int vector[1000]; 
    int numero = 546; 
    int mitad = 0;
    int comienzo = 0;
    int final = 999; 

    for (i=0; i < 1000; i++)
        vector[i] = i;	      /* Asigna valor al vector */

    mitad = (final + comienzo) / 2;

     /* Bucle de búsqueda */
    while (comienzo <= final && vector[mitad] != numero)   
    {
        printf ("Acotando a %d \n", mitad);
	if (vector[mitad] < numero) 
            comienzo = mitad + 1;       
        else
            final = mitad - 1;

        mitad = (final + comienzo) / 2;
    }

    if (comienzo <= final)
        printf ("El numero buscado está en %d \n", mitad);
    else
        printf ("El numero no está\n");
    return (0);
}      
