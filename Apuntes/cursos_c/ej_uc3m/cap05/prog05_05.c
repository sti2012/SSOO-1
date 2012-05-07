/*
 * Programa:    prog_05_05
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 5:
 *              Programa que ejecuta una cuenta atras
 */
#include <stdio.h>

int main()
{
    int numero;
    int indice;
    
    /*
     * Leer el inicio de la cuenta atr�s 
     */
    printf ("Introduzca el inicio de la cuenta atr�s: ");
    scanf ("%d", &numero);

    printf ("Comienza la cuenta atr�s:\n");
    for (indice = numero; 0 <= indice; indice = indice - 1) {
        printf ("%d\n",indice);
    }
    printf ("Despegue...\n");
    return(0);
}

