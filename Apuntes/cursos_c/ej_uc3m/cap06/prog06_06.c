/*
 * Programa:    prog_06_06
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 6:
 *              Programa que utiliza el operador sizeof()
 */
#include <stdio.h>

int main(void) 
{

    long Dato = 0x41413737;
    long * refDatoLong;
    short * refDatoShort;
    void * refDatoVoid;

    /* Asignar la direcci�n de un long al puntero a long */
    refDatoLong = &Dato;

    /* Convertir un puntero a long en un puntero a short */ 
    /* Utilizando un puntero a void */
    refDatoVoid = refDatoLong;
    refDatoShort = refDatoVoid;

    printf("El tama�o del tipo long es  = %d\n", sizeof(long));
    printf("El tama�o del tipo short es = %d\n", sizeof(short));
    printf("El tama�o de un tipo puntero es = %d\n\n", sizeof(void *));

    printf("El tama�o de la variable Dato es = %d\n", sizeof(Dato));
    printf("El tama�o de la variable puntero refDatoLong es = %d\n",
                            sizeof(refDatoLong));
    printf("El tama�o del dato referenciado por refDatoLong es = %d\n",      
                             sizeof(*refDatoLong));
    printf("El tama�o de la variable puntero refDatoShort es = %d\n",
                            sizeof(refDatoShort));
    printf("El tama�o del dato referenciado por refDatoShort es = %d\n",        
                            sizeof(*refDatoShort));
    return(0);
}

