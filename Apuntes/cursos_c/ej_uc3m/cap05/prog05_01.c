/*
 * Programa:    prog_05_01
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 5:
 *              Programa que lee un n�mero y dice si es par
 */
#include <stdio.h>

int main()
{
    int numero;
    
    /*
     * Leer el numero
     */
    printf ("Introduzca un n�mero: ");
    scanf ("%d", &numero);

    if (0 == (numero % 2)) 
        printf ("El n�mero %d es par.\n",numero);
    return(0);
}

