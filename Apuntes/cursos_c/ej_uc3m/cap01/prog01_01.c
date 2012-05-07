/*                                                                               * Programa:    prog_01_01
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 1:
 *              Búsqueda sin optimizar de un número.
 */

#include <stdio.h>
    
int main (int argc, char **argv)
{
    int i = 0;
    int vector[1000]; 
    int numero = 546; 
    int encontrado = 0;

    for (i=0; i < 1000; i++)
        vector[i] = i;        /* Asigna valor al vector */

    i = 0;
    while ((i<1000) && (encontrado == 0))  /* Bucle de búsqueda */
    {
        if (vector[i] == numero) 
        {
            encontrado = 1;
        }
        else 
	    i = i+1;
    }

    if (encontrado == 1)
        printf ("Encontrado número %d \n", numero);       
    else
        printf ("Número no encontrado\n");


    return (0);
}      

