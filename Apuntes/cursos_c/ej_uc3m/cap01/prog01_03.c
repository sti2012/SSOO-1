/*                                                                               * Programa:    prog_01_03
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 1:
 *              Búsqueda rápida de un número con una función.
 */


#include <stdio.h>

/*
 * Prototipo de funciones
 */
int buscar (int *vect, int comienzo, int final, int objetivo);
 
int main (int argc, char **argv)
{
    int i = 0;
    int vector[1000]; 
    int numero = 546; 
    int inicio = 0;
    int fin = 999; 

    for (i=0; i < 1000; i++)
        vector[i] = i;	      /* Asigna valor al vector */

    i = buscar (vector, inicio, fin, numero);

    if (i != -1)
        printf ("El numero buscado está en %d \n", i);
    else
        printf ("El numero no está en el vector\n");

    return (0);
}      

/*
 * Función buscar. 
 * Devuelve el índice en el que se encuentra objetivo
 * -1 si el objetivo no se encuentra
 */
int buscar (int *v, int comienzo, int final, int objetivo)
{ 
    int mitad = 0;

    mitad = (final + comienzo) / 2;

     /* Bucle de búsqueda */
    while (comienzo <= final && v[mitad] != objetivo)
    {
        printf ("Acotando a %d \n", mitad);
        if (v[mitad] < objetivo)
            comienzo = mitad + 1;
        else
            final = mitad - 1;

        mitad = (final + comienzo) / 2;
    }

    if (comienzo <= final)
        return(mitad);
    else
        return(-1);

}

