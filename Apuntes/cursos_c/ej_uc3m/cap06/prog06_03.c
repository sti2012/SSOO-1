/*
 * Programa:    prog_06_03
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 6:
 *              Programa que convierte punteros de tipo base
 */
#include <stdio.h>

int main(void) 
{
    long Dato = 0x41414141;
    long * refDatoLong;
    short * refDatoShort;

    /* Asignar la direcci�n de un long al puntero a long */
    refDatoLong = &Dato;

    /* Convertir un puntero a long en un puntero a short */
    /* Al compilar provocar� un warning */
    refDatoShort = refDatoLong;

    printf("La direcci�n almacenada en refDatoLong es  = %p\n",refDatoLong);
    printf("El dato referenciado por refDatoLong es    = 0x%lx\n\n",*refDatoLong);

    printf("La direcci�n almacenada en refDatoShort es = %p\n",refDatoShort);
    printf("El dato referenciado por refDatoShort es   = 0x%x\n",*refDatoShort);
    return(0);
}

