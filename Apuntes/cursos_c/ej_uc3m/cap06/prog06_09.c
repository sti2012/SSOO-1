/*
 * Programa:    prog_06_09
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 6:
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

    printf("La dirección almacenada en refDato es %p\n", refDato);
    printf("La dirección almacenada en refRefDato es %p\n", refRefDato);

    printf("El valor almacenadio en Dato es %ld\n", *refDato);
    printf("El valor almacenadio en refDato es %p\n", *refRefDato);

    printf("El valor almacenadio en Dato es %ld\n", **refRefDato);

    return(0);
}

