/*
 * Programa:    prog_06_02
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 6:
 *              Programa que devuelve el contenido y la dirección de algunas
 *              variable
 */
#include <stdio.h>

int main(void) {

    long Dato = 0;
    long * refDato;

    refDato = &Dato;
    printf("La dirección de la variable Dato es = %p\n",&Dato);
    printf("El valor de la variable refDato es = %p\n",refDato);

    Dato = 10;
    printf("El contenido de la variable Dato es = %ld\n", Dato);
    printf("El contenido de la dir. almacenada en refDato es = %ld\n", *refDato);
					    
    *refDato = 5;
    printf("El nuevo contenido de la variable Dato es = %ld\n", Dato);
    printf("El nuevo contenido de la dir. almacenada en refDato es = %ld\n", 
                              *refDato);
    return(0);
}

