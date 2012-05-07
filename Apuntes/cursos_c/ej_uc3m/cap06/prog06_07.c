/*
 * Programa:    prog_06_07
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 6:
 *              Programa que accede a un puntero nulo
 */
#include <stdio.h>

int main(void) 
{

    long * refDatoLong = NULL;
    long aux;

    printf("La direcci�n almacenada en refDatoLong = %p\n", refDatoLong);

    /* Comprobar si el puntero es nulo */
    if (NULL == refDatoLong) {
        printf("El puntero refDatoLong es nulo\n");
    }
    /*Prueba de acceso al contenido de refDatoLong, deber�a dar error */
    printf ("Acceso al contenido de refDatoLong, debe de producirse un error");
    aux = *refDatoLong;
				    
    return(0);
}

