/*
 * Programa:    prog_06_10
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 6:
 *              Programa con errores
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    long Dato = 0x41413737;
    long * refDatoLong;
    short * refDatoShort;
    void * refDatoVoid;

    /* Asignando un valor a la memoria referenciada por refDatoShort*/
    (*refDatoShort) = 0x4141;

    /* Convertir un puntero a long en un puntero a short */ 
    refDatoShort = refDatoLong;

    /* Asignando memoria dinámica */
    refDatoLong = malloc(sizeof(long));

    (*refDatoLong) = 0x41414141;

    /* Asignando la dirección de una variable */
    refDatoLong = &Dato;

    /* Referenciando a la posición contigua */
    *(refDatoLong + 1) = 0x90904141

    /* Libera la memoria */
    free(refDatoLong);
						    
return(0);
}

