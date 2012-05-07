/*
 * Programa:    prog_05_02
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 5:
 *              Programa que lee un n�mero y devuelve su cuadrado
 */
#include <stdio.h>

int main()
{
    int numero;
    int cuadrado;
    
    /*
     * Leer el numero
     */
    printf ("Introduzca un n�mero: ");
    scanf ("%d", &numero);

    if (0 == (numero % 2)) {
        cuadrado = numero * numero;
        printf ("El cuadrado de %d es %d.\n",numero, cuadrado);
    }
    return(0);
}

