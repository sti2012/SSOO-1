/*
 * Programa:    prog_06_06
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 6:
 *              Programa que utiliza el operador sizeof()
 */
#include <stdio.h>

int main(void) 
{

    long Dato = 0x41413737;
    long * refDatoLong;
    short * refDatoShort;
    void * refDatoVoid;

    /* Asignar la dirección de un long al puntero a long */
    refDatoLong = &Dato;

    /* Convertir un puntero a long en un puntero a short */ 
    /* Utilizando un puntero a void */
    refDatoVoid = refDatoLong;
    refDatoShort = refDatoVoid;

    printf("El tamaño del tipo long es  = %d\n", sizeof(long));
    printf("El tamaño del tipo short es = %d\n", sizeof(short));
    printf("El tamaño de un tipo puntero es = %d\n\n", sizeof(void *));

    printf("El tamaño de la variable Dato es = %d\n", sizeof(Dato));
    printf("El tamaño de la variable puntero refDatoLong es = %d\n",
                            sizeof(refDatoLong));
    printf("El tamaño del dato referenciado por refDatoLong es = %d\n",      
                             sizeof(*refDatoLong));
    printf("El tamaño de la variable puntero refDatoShort es = %d\n",
                            sizeof(refDatoShort));
    printf("El tamaño del dato referenciado por refDatoShort es = %d\n",        
                            sizeof(*refDatoShort));
    return(0);
}

