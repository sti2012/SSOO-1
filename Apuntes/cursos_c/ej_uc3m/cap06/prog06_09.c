/*
 * Programa:    prog_06_09
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 6:
 *              Programa que utiliza punteros de punteros
 */
#include <stdio.h>

int main(void) 
{
	    
    long Dato = 9;
    long *refDato;
    long **refRefDato;

    refDato = &Dato;
    refRefDato = &refDato;

    printf("La direcci�n almacenada en refDato es %p\n", refDato);
    printf("La direcci�n almacenada en refRefDato es %p\n", refRefDato);

    printf("El valor almacenadio en Dato es %ld\n", *refDato);
    printf("El valor almacenadio en refDato es %p\n", *refRefDato);

    printf("El valor almacenadio en Dato es %ld\n", **refRefDato);

    return(0);
}

