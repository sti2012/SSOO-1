/*
 * Programa:    prog_06_01
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 6:
 *              Programa que devuelve el contenido y la dirección de una
 *              variable
 */
#include <stdio.h> 

int main(void)  
{
    long Dato = 0;
    long * refDato;

    refDato = &Dato;
    printf("La dirección de la variable Dato es = %p\n",&Dato);
    printf("El valor de la variable refDato es = %p\n",refDato);
    return(0);
}

