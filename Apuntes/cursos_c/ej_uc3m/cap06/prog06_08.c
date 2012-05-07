/*
 * Programa:    prog_06_08
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 6:
 *              Programa que gestiona memoria dinámica con malloc y free
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

    printf("La dirección devuelta por malloc es = %p\n",refDatoLong);
    printf("El dato almacenado en esa dirección es = 0x%lx\n",*refDatoLong);

    /* Libera la memoria */
    free(refDatoLong);
    refDatoLong = NULL;
    system("pause");
    return(0);
}

