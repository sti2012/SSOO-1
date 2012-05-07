/*
 * Programa:    prog_06_03
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 6:
 *              Programa que convierte punteros de tipo base
 */
#include <stdio.h>

int main(void) 
{
    long Dato = 0x41414141;
    long * refDatoLong;
    short * refDatoShort;

    /* Asignar la dirección de un long al puntero a long */
    refDatoLong = &Dato;

    /* Convertir un puntero a long en un puntero a short */
    /* Al compilar provocará un warning */
    refDatoShort = refDatoLong;

    printf("La dirección almacenada en refDatoLong es  = %p\n",refDatoLong);
    printf("El dato referenciado por refDatoLong es    = 0x%lx\n\n",*refDatoLong);

    printf("La dirección almacenada en refDatoShort es = %p\n",refDatoShort);
    printf("El dato referenciado por refDatoShort es   = 0x%x\n",*refDatoShort);
    return(0);
}

