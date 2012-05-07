/*                                                                               * Programa:    prog_01_02
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 1:
 *              B�squeda r�pida de un n�mero.
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

     /* Bucle de b�squeda */
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
        printf ("El numero buscado est� en %d \n", mitad);
    else
        printf ("El numero no est�\n");
    return (0);
}      
