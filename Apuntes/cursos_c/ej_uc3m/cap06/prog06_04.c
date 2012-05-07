/*
 * Programa:    prog_06_04
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 6:
 *              Programa que convierte punteros de tipo base distinto usando un
 *              puntero auxiliar (void *)
 */
#include <stdio.h>

int main(void) {

    long Dato = 0x41414141;
    long * refDatoLong;
    short * refDatoShort;
    void * refDatoVoid;

    /* Asignar la dirección de un long al puntero a long */
    refDatoLong = &Dato;

    /* Convertir un puntero a long en un puntero a short */ 
    /* Utilizando un puntero a void */
    refDatoVoid = refDatoLong;
    refDatoShort = refDatoVoid;
    
    printf("La dirección almacenada en refDatoLong es  = %p\n",refDatoLong);
    printf("El dato referenciado por refDatoLong es    = 0x%lx\n\n",*refDatoLong);

    printf("La dirección almacenada en refDatoShort es = %p\n",refDatoShort);
    printf("El dato referenciado por refDatoShort es   = %x\n",*refDatoShort);
						    
    printf("La dirección almacenada en refDatoVoid es = %p\n",refDatoVoid);

    return(0);
}

