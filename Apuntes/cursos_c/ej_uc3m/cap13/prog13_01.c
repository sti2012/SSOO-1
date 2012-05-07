/* 
 * Programa:    prog13_01
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 13:
 *              Programa que utiliza los parametros de la funcion main
 */
#include <stdio.h>

int main (int argc, char *argv[])
{
    int i;

    printf("El número de argumentos es %d \n", argc);
    for (i = 0; i < argc; i++) {
        printf("El argumento %d es %s \n", i, argv[i]);
    }

    return (0);
}

