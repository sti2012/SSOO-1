/*
 * Programa:    prog_06_01
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 6:
 *              Programa que devuelve el contenido y la direcci�n de una
 *              variable
 */
#include <stdio.h> 

int main(void)  
{
    long Dato = 0;
    long * refDato;

    refDato = &Dato;
    printf("La direcci�n de la variable Dato es = %p\n",&Dato);
    printf("El valor de la variable refDato es = %p\n",refDato);
    return(0);
}

