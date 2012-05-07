/*
 * Programa:    prog_06_08
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 6:
 *              Programa que gestiona memoria din�mica con malloc y free
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    long * refDatoLong = NULL;
	        
    /* Reserva memoria para un dato de tipo long */
    refDatoLong = malloc(sizeof(long));
    if (NULL == refDatoLong) {
        printf("Error, no hay memoria\n");
        return(-1);
    }

    (*refDatoLong) = 0x41414141;

    printf("La direcci�n devuelta por malloc es = %p\n",refDatoLong);
    printf("El dato almacenado en esa direcci�n es = 0x%lx\n",*refDatoLong);

    /* Libera la memoria */
    free(refDatoLong);
    refDatoLong = NULL;
    system("pause");
    return(0);
}

