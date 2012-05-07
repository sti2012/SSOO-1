/*
 * Programa:    prog_05_06
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 5:
 *              Programa que lee un n�mero y devuelve la suma desde 1 hasta el
 *              n�mero
 */
#include <stdio.h>

int main()
{
    int numero;
    int suma = 0;
    
    /*
     * Leer el numero. Debe ser mayor que cero 
     */
    printf ("Introduzca un n�mero (Debe ser mayor que 0): ");
    scanf ("%d", &numero);

    do {
        suma = suma + numero;
        numero = numero - 1;
    } while (0 < numero);
    printf ("El resultado de sumar 1+2+...+N es %d.\n",suma);
    return(0);
}

