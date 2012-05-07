/*
 * Programa:    prog_06_07
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 6:
 *              Programa que accede a un puntero nulo
 */
#include <stdio.h>

int main(void) 
{

    long * refDatoLong = NULL;
    long aux;

    printf("La dirección almacenada en refDatoLong = %p\n", refDatoLong);

    /* Comprobar si el puntero es nulo */
    if (NULL == refDatoLong) {
        printf("El puntero refDatoLong es nulo\n");
    }
    /*Prueba de acceso al contenido de refDatoLong, debería dar error */
    printf ("Acceso al contenido de refDatoLong, debe de producirse un error");
    aux = *refDatoLong;
				    
    return(0);
}

