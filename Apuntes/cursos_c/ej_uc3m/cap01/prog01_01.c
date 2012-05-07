/*                                                                               * Programa:    prog_01_01
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 1:
 *              B�squeda sin optimizar de un n�mero.
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
    while ((i<1000) && (encontrado == 0))  /* Bucle de b�squeda */
    {
        if (vector[i] == numero) 
        {
            encontrado = 1;
        }
        else 
	    i = i+1;
    }

    if (encontrado == 1)
        printf ("Encontrado n�mero %d \n", numero);       
    else
        printf ("N�mero no encontrado\n");


    return (0);
}      

