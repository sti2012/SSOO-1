/*                                                                               * Programa:    prog_01_03
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 1:
 *              B�squeda r�pida de un n�mero con una funci�n.
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
        printf ("El numero buscado est� en %d \n", i);
    else
        printf ("El numero no est� en el vector\n");

    return (0);
}      

/*
 * Funci�n buscar. 
 * Devuelve el �ndice en el que se encuentra objetivo
 * -1 si el objetivo no se encuentra
 */
int buscar (int *v, int comienzo, int final, int objetivo)
{ 
    int mitad = 0;

    mitad = (final + comienzo) / 2;

     /* Bucle de b�squeda */
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

